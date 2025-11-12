#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,p[N],w[N],ans;
bool ss[N],use[N];
inline bool check()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(p[w[i]]<=cnt||!ss[i])
        {
            cnt++;
        }
    }
    return n-cnt>=m;
}
inline void dfs(int x)
{
    if(x>n)
    {
        if(check())
        {
            ans++;
            return;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!use[i])
        {
            use[i]=1;
            w[x]=i;
            dfs(x+1);
            use[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    string s;
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            ss[i+1]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}