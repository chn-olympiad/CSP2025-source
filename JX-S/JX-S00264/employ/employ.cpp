#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const ll N=505,mod=998244354;
int n,m;
char c[N];
int a[N];
bool vis[N];
ll ans=0;
inline void dfs(int x,int k,int l)
{
    if(x==n+1)
    {
        ans+=(k>=m);
        if(ans>=mod)ans-=mod;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            if(c[x]=='0'||l>=a[i])dfs(x+1,k,l+1);
            else dfs(x+1,k+1,l);
            vis[i]=0;
        }
    }
    return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(c[i]=='0'||a[i]==0)
            {
                cout<<0;
                return 0;
            }
        }
        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*i%mod;
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
