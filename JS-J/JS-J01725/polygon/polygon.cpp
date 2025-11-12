#include<bits/stdc++.h>
#define N 5005
#define MOD 998244353
using namespace std;
int  n,a[N];
long long sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n==3)
    {
        for(int i=1;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<=n;k++)
                {
                    if((a[i]+a[j]+a[k])>2*max(max(a[i],a[j]),a[k]))
                        sum++;
                }
        printf("%lld",sum%MOD);
        return 0;
    }
    return 0;
}
