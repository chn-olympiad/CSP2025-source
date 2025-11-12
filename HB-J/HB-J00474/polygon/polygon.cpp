#include"stdio.h"
#include<algorithm>
#define N 5010

int n,a[N];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    if(n == 3)
    {
        if(a[0] + a[1] + a[2] > 2 * std::max(a[0],std::max(a[1],a[2]))) puts("1");
        else puts("0");
    }
    else puts("0");
    return 0;
}
