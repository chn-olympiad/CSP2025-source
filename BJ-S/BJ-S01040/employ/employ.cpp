#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510],c[510],ans=0;
string s;
bool vis[510];
bool cnt()
{
    int pass=0,cur=0;
    for(int i=1;i<=n;i++)
    {
        int fail=(i-1-pass);
        if(fail>=c[i])continue;
        if(s[i-1]=='1')pass++;
    }
    return pass>=m;
}
void dfs(int step)
{
    if(step>n)
    {
        if(cnt())ans++;
        ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        vis[i]=1;
        c[step]=a[i];
        dfs(step+1);
        vis[i]=0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
