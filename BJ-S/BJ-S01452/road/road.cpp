#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    srand(time(0));
    printf("%d\n",abs(rand()%100000-40000));
    return 0;
}
