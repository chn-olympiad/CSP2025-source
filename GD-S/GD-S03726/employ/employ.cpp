#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
using namespace std;
const int mod=998244353;
int T,n,m,ans;
int c[505];
int fac[505];
string s;
int vis[15];
vector<int> p;
void dfs(int x)
{
    if(x>n)
    {
        int res=0,pre=0;
        rep(i,1,n)
        {
            if(s[i]=='0'||pre>=c[p[i-1]])
            {
                pre++;
                continue;
            }
            else res++;
        }
        if(res>=m) ans++;
        return;
    }
    rep(i,1,n)
    {
        if(!vis[i])
        {
            vis[i]=1,p.push_back(i);
            dfs(x+1);
            vis[i]=0,p.pop_back();
        }
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s,s=" "+s;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod,cin>>c[i],fac[1]=1;
    dfs(1),cout<<ans;
    return 0;
}