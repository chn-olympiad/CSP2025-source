#include<bits/stdc++.h>
using namespace std;
int c[510],cnt,n,m,ans;
int p[510];
int vis;
string s;
void dfs(int u)
{
    if(u==n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=c[p[i]]||s[i]=='0')cnt++;
        }
        //cout<<cnt<<endl;
        if(n-cnt>=m) ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis&(1<<(i-1))) continue;
        p[u+1]=i;
        vis=vis+(1<<(i-1));
        dfs(u+1);
        vis=vis-(1<<(i-1));
    }
    return ;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s='a'+s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
