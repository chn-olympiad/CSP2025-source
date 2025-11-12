#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int a,b,c;
}s[100005];
bool cmp(node x,node y)
{
    return max({x.a,x.b,x.c})>max({y.a,y.b,y.c});
}
ll dp[100005][4];
int vis[4];
ll dp1[205][105][105];
void solve1(int n)
{
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=min(i,n/2);j++)
        {
            for(int k=0;k<=min(i,n/2)&&k+j<=i;k++)
            {
                if(i-j-k>n/2)continue;
                if(j)dp1[i][j][k]=max(dp1[i-1][j-1][k]+s[i].a,dp1[i][j][k]);
                if(k)dp1[i][j][k]=max(dp1[i-1][j][k-1]+s[i].b,dp1[i][j][k]);
                if(i-j-k)dp1[i][j][k]=max(dp1[i-1][j][k]+s[i].c,dp1[i][j][k]);
                ans=max(ans,dp1[i][j][k]);
            }
        }
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n/2;j++)
            for(int k=0;k<=n/2;k++)
                dp1[i][j][k]=0;
    cout<<ans<<"\n";
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>s[i].a>>s[i].b>>s[i].c;
        if(n<=200)
        {
            solve1(n);
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][1]=max(dp[i-1][2],dp[i-1][3])+s[i].a;
            dp[i][2]=max(dp[i-1][1],dp[i-1][3])+s[i].b;
            dp[i][3]=max(dp[i-1][1],dp[i-1][2])+s[i].c;
            // cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<"\n";
        }
        // cout<<max({dp[n][1],dp[n][2],dp[n][3]})<<"\n";
        sort(s+1,s+n+1,cmp);
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            vector<int> tmp;
            int mx=-114514;
            if(vis[1]<n/2)  mx=max(s[i].a,mx);
            if(vis[2]<n/2)  mx=max(s[i].b,mx);
            if(vis[3]<n/2)  mx=max(s[i].c,mx);
            if(mx==s[i].a)  tmp.push_back(1);
            if(mx==s[i].b)  tmp.push_back(2);
            if(mx==s[i].c)  tmp.push_back(3);
            sort(tmp.begin(),tmp.end(),[](int x,int y){return vis[x]<vis[y];});
            if(tmp[0]==1)   ans+=s[i].a,vis[1]++;
            if(tmp[0]==2)   ans+=s[i].b,vis[2]++;
            if(tmp[0]==3)   ans+=s[i].c,vis[3]++;
        }
        cout<<max({ans,dp[n][1],dp[n][2],dp[n][3]})<<"\n";
        vis[0]=vis[1]=vis[2]=vis[3]=0;
    }
    return 0;
}
