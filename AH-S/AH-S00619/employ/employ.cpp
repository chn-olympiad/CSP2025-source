#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int vis[505],a[505],b[505],ans,n,m,cnt,c[505][505],sum;
void dfs(int k,int jiapang,int bt)
{
    if(bt>=m)
    {
        ans++;
        return;
    }
    if(k>n)return;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(jiapang>=a[i])continue;
            vis[i]=1;
            if(b[k]==0)dfs(k+1,jiapang+1,bt);
            else dfs(k+1,jiapang,bt+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    c[1][1]=1;
    for(int i=1; i<=500; i++)
    {
        for(int j=1; j<=500; j++)
        {
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    cin>>n>>m;
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    cnt=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%1d",&b[i]);
        if(b[i]==1)cnt++;
    }
    if(cnt<m)
    {
        cout<<"0";
        return 0;
    }
    if(cnt==n)
    {
        cout<<c[n][m];
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
