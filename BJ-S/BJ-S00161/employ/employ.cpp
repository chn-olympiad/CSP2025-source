#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[510];
long long ans;
bool canjia[510];
int s0,s1;
void dfs(int u,int dep)
{
    if(u>n)
        return ;
    if(dep>=m)
    {
        ans++;
        ans%=998244353;
        return ;
    }
    if(dep<c[u]&&s1)
    {
        canjia[u]=1;
        s1--;
        dfs(u+1,dep+1);
        s1++;
    }
    canjia[u]=0;
    dfs(u+1,dep+1);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')s0++;
        if(s[i]=='1')s1++;
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    dfs(1,1);
    cout<<ans;
    return 0;
}
