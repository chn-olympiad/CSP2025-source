#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
struct club{
    int a,b,c;
} m[500005];

/*
int dp[500005][3];

int p[3];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i].a>>m[i].b>>m[i].c;
    }
    dp[1][1]=m[1].a;
    dp[1][2]=m[1].b;
    dp[1][3]=m[1].c;

    if(max({dp[1][1],dp[1][2],dp[1][3]})==dp[1][1]) p[1]++;
    else if(max({dp[1][1],dp[1][2],dp[1][3]})==dp[1][2]) p[2]++;
    else p[3]++;

    for(int i=2;i<=n;i++)
    {
        if(p[1]<n/2) dp[i][1]=max({dp[i-1][1],dp[i-1][2],dp[i-1][3]})+m[i].a;
        if(p[2]<n/2) dp[i][2]=max({dp[i-1][1],dp[i-1][2],dp[i-1][3]})+m[i].b;
        if(p[3]<n/2) dp[i][3]=max({dp[i-1][1],dp[i-1][2],dp[i-1][3]})+m[i].c;

        if(max({dp[i][1],dp[i][2],dp[i][3]})==dp[i][1]) p[1]++;
        else if(max({dp[i][1],dp[i][2],dp[i][3]})==dp[i][2]) p[2]++;
        else p[3]++;

        cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
    }
    cout<<endl;
    cout<<p[1]<<" "<<p[2]<<" "<<p[3]<<endl;
    cout<<max({dp[n][1],dp[n][2],dp[n][3]})<<endl;
    return 0;
}
*/



int ans=0;
int p[4];

void dfs(int x,int t)
{
    if(x>n)
    {
        ans=max(ans,t);
        return;
    }
    if(p[1]<n/2){p[1]++;dfs(x+1,t+m[x].a);p[1]--;}
    if(p[2]<n/2){p[2]++;dfs(x+1,t+m[x].b);p[2]--;}
    if(p[3]<n/2){p[3]++;dfs(x+1,t+m[x].c);p[3]--;}
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int m;
    cin>>m;
    while(m--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>m[i].a>>m[i].b>>m[i].c;
        dfs(1,0);
        cout<<ans<<endl;
    }
}
