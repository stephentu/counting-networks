#include "balancer.h"

void
balancer_init_leaf(struct balancer *b,
                   void *op_first,
                   void *op_second)
{
  b->l = 1;
  b->s = 0;
  b->links[0].opaque = op_first;
  b->links[1].opaque = op_second;
  b->next = 0;
}

void
balancer_init_nonleaf(struct balancer *b,
                      struct balancer *first,
                      struct balancer *second)
{
  b->l = 0;
  b->s = 0;
  b->links[0].b = first;
  b->links[1].b = second;
  b->next = 0;
}
