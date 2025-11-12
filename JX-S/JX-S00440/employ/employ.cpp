#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int a[505];
bool done[505];
int jl[505];
int ans=0;
void solve()
{
    int js=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0'||js>=a[jl[i]])
        {
            js++;
        }
    }
    if(n-js>=m)
    {
        ans++;
    }
}
void dfs(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(done[i])
        {
            continue;
        }
        jl[x]=i;
        done[i]=true;
        if(x==n)
        {
            solve();
        }
        else
        {
            dfs(x+1);
        }
        done[i]=false;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s+1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}
