#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans;
ll a[500005];
bool f[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for (int i=1;i<=n;i++) f[i]=1;
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if (a[i]==k)
        {
            ans++;
            f[i]=0;
        }
    }
    for (int len=2;len<=n;len++)
    {
        for (int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if (f[i]==0 || f[j]==0) break;
            ll sum=a[i];
            for (int w=i+1;w<=j;w++)
            {
                sum=sum|a[w];
            }
            if (sum==k)
            {
                ans++;
                for (int w=i;w<=j;w++) f[w]=0;
            }
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
