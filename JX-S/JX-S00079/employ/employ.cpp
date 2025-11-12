#include<bits/stdc++.h>
using namespace std;
const int N=510;
string s;
const int Mod=998244353;
int peo[N];
long long ans=0;
int n,m;
bool vis[N];
long long f[N];
void dfs(int u,int day,int tt)
{
    if(vis[u])return;
    vis[u]=1;
    if(tt>=peo[u]||(!(s[day])-'0'))tt++;
    if(tt>n-m)
    {
        return;
    }
    if(n-tt>=m)
    {
        ans=(ans%Mod)+(f[n-day-1]%Mod);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,day+1,tt);
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    f[0]=1;
    for(int i=1;i<=n;i++){cin>>peo[i];f[i]=f[i-1]*i%Mod;}
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        dfs(i,1,0);
    }
    cout<<ans;
    return 0;
}
