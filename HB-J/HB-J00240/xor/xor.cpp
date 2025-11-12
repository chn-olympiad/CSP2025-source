#include <iostream>
#include <cstdio>
using namespace std;
int n,ans;
long long k;
long long a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(k==0)
    {
        for(int i=2;i<=n;i+=2)
        {
            ans+=n/i;
        }
        printf("%d",ans);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int l=1;l<=n-i;l++)
            {
                long long cnt=a[l];
                int r=l+i-1;
                for(int j=l+1;j<=r;j++)
                {
                    cnt=cnt^a[j];
                }
                if(cnt==k)
                {
                    ans++;
                }
            }
        }
        printf("%d",ans);
    }
    return 0;
}
