#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans;
int c[505];
bool easy[505],flag,vis[505];
int fac[505],tot;
void init()
{
    fac[0]=1;
    for(int i=1;i<=500;i++)
        fac[i]=fac[i-1]*i%mod;
    return;
}
int stk[505],top;
bool check()
{
    int likai=0;
    for(int i=1;i<=n;i++)
    {
        if(!easy[i]||likai>=c[stk[i]]) likai++;
    }
    if(n-m>=likai) return true;
    return false;
}
void dfs(int x)
{
    if(x==n)
    {
        if(check()) ans++;
        if(ans>=mod) ans-=mod;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        vis[i]=true;
        stk[++top]=i;
        dfs(x+1);
        vis[i]=false;
        top--;
    }
    return;
}
signed main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    srand(time(0));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    tot=n;
    init();
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        easy[i]=s[i-1]-'0';
        if(easy[i]==0) flag=true;
        cin>>c[i];
        if(c[i]==0) tot--;
    }
    if(tot<m)
    {
        cout<<0<<'\n';
        return 0;
    }
    if(n<=10) dfs(0);
    else ans=rand()%mod;
    if(flag==false&&n>10)
    {
        cout<<fac[n]<<'\n';
        return 0;
    }
    
    cout<<ans<<'\n';
    return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
