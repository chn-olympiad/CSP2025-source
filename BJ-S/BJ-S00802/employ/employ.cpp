#include<iostream>
using namespace std;
string s;
int n,m,ans,a[20],c[20];
bool vis[20];
bool check()
{
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(c[a[i]]<=cnt2) cnt2++;
        else if(s[i]=='0') cnt2++;
        else cnt1++;
    }
    return cnt1>=m;
}
void dfs(int step)
{
    if(step>n)
    {
        if(check()) ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0) continue;
        a[i]=step;
        dfs(step+1);
        a[i]=0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ,out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1);
    cout<<ans;
    return 0;
}
