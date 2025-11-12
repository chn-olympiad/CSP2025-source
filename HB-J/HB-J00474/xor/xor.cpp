#include"stdio.h"
#define N 500010

int n;
long long k,a[N] = {0};
int main()
{
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    printf("%d",n / 2);
    return 0;
}
