#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int p[505],a[505],vis[505];
int ans;
void dfs(int len)
{
    if(len==n+1)
    {
        int c=0,x=0;
        for(int i=1;i<=n;i++)
        {
            if(c>=a[i]||s[i]=='0')  c++;
            else    x++;
        }
        if(x>=m)    ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])  continue;
        vis[i]=1;
        a[len]=p[i];
        dfs(len+1);
        a[len]=0;
        vis[i]=0;
    }
}
void solve1()
{
    dfs(1);
    cout<<ans%998244353<<"\n";
}
void solve2()
{
    sort(s.begin(),s.end());
    if(s[1]!='1')   cout<<"0\n";
    else
    {
        int tmp=0;
        for(int i=1;i<=n;i++)
            tmp+=(p[i]==0);
        int fac=1;
        for(int i=1;i<=n;i++)
            fac=1ll*fac*i%998244353;
        if(n-tmp>=m)cout<<fac<<"\n";
        else    cout<<"0\n";
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s="_"+s;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    if(n<=20)solve1();
    else    solve2();
    return 0;
}