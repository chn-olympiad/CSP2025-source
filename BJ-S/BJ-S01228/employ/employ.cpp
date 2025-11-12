#include <bits/stdc++.h>
#define int long long
#define N 505
#define mod 998244353

using namespace std;

int n,m,p[N],tmp,ans;
bool flag=1;
string s;
signed main()
{
    freopen("employ3.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=0;i<s.size();i++)
        if(s[i]!='1'){flag=0,tmp=i+1;break;}
    if(flag)
    {
        ans=1;
        for(int i=n;i>n-m;i--)
            ans=(ans*i)%mod;
        cout<<ans<<'\n';
    }
    else
    {
        for(int i=1;i<=n;i++)
            if(p[i]>=tmp)ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
