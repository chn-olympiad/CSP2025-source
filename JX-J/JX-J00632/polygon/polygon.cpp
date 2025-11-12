#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int c(int o,int p)
{
    int m1=1;
    for(int i=p;i>=p-o+1;--i)
    {
        m1*=i;
        m1%=998244353;
    }
    int m2=1;
    for(int i=2;i<=o;++i)
    {
        m2*=i;
        m2%=998244353;
    }
    if(m2!=0)
        return m1/m2%998244353;
    return 0;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        int a;
        scanf("%lld",&a);
        if(a==1)
        {
              ++cnt;
        }
    }
    int ans=0;
    for(int i=3;i<=cnt;++i)
    {
        ans+=c(i,cnt)%998244353;
        ans%=998244353;
    }
    printf("%lld",ans%998244353);
    return 0;
}
