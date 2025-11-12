#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,cnt=0;
    scanf("%lld %lld",&n,&m);
    string s;
    cin>>s;
    for(int i=1;i<=n;++i)
    {
        int c;
        scanf("%lld",&c);
        if(c==0)
        {
            ++cnt;
        }
    }
    int ans=1;
    if(n-cnt<m)
    {
        cout<<0;
        return 0;
    }
    else
    {
        for(int i=1;i<=n;++i)
        {
            ans*=i;
            ans%=MOD;
        }
    }
    printf("%lld",ans);
    return 0;
}
