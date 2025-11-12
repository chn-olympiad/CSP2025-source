#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool a[5020];
int d[5020];
int n;
ll ans=0;
bool judge()
{
    int sumn=0,mx=-1;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i])
        {
            sumn++;
            mx=max(mx,d[i]);
            sum+=d[i];
        }
    }
    if(sumn>=3&&sum>mx*2)return true;
    else return false;
}
void dfs(int now)
{
    if(now-1==n)
    {
        if(judge())ans++;
        return;
    }
    else
    {
        dfs(now+1);
        a[now]=true;
        dfs(now+1);
        a[now]=false;
    }
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
