#include<bits/stdc++.h>
using namespace std;
const int N=514;
int n,m,a[N],t[N],l[N],vis[N],ans;
string s;
void check()
{
    int f=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(f>=a[l[i]]||!t[i])
        {
            f++;
        }
        else
        {
            cnt++;
        }
    }
    if(m<=cnt)
    {
        ans++;
    }
}
void dfs(int x)
{
    if(x>n)
    {
        check();
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            l[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        t[i+1]=s[i]-'0';
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}