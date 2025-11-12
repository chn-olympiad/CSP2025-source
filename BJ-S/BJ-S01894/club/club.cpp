#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
ll T;
ll n;
ll maxi;
ll a[100010][5];
ll dp[100010][5];
ll b[5];
void dfs(ll x,ll ans)
{
    if(x==n+1)
    {
        maxi=max(maxi,ans);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(b[i]<n/2)
        {
            b[i]++;
            dfs(x+1,ans+a[x][i]);
            b[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        maxi=-1e18;
        memset(b,0,sizeof(b));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1,0);
        cout<<maxi<<endl;
    }
    return 0;
}
