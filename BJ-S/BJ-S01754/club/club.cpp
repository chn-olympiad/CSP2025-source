#include<bits/stdc++.h>
using namespace std;
int dp[205][205][205];
int n,t;
int a[200005][5];
set<int> s2;
set<int> s3;
priority_queue<int,vector<int>,less<int> > pq1;
priority_queue<int,vector<int>,greater<int> > pq2;
void solveA()
{
    //cout<<"A";
    while(!pq1.empty())
        pq1.pop();
    for(int i=1;i<=n;i++)
        pq1.push(a[i][1]);
    //while(!pq.empty())
    //    cout<<pq.top()<<" ",pq.pop();
    //cout<<endl;
    int cnt=0;
    int ans=0;
    //if(pq.empty())
    //    return ;
    while(1)
    {
        cnt++;
        if(cnt>n/2)
            break;
        int cur=pq1.top();
        pq1.pop();
        ans+=cur;
    }
    cout<<ans<<endl;
}
void solveB()
{
    int ans=0,cnt=0;
    while(!pq2.empty())
        pq2.pop();
    for(int i=1;i<=n;i++)
    {
        pq2.push(a[i][1]-a[i][2]);
        ans+=a[i][1];
    }
    while(1)
    {
        cnt++;
        if(cnt>n/2)
            break;
        int cur=pq2.top();
        pq2.pop();
        ans-=cur;
    }
    cout<<ans<<endl;
}
void solvedp()
{
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        for(int x=0;x<=min(i,n/2);x++)
        {
            for(int y=0;x+y<=i && y<=n/2;y++)
            {
                if(x!=0)
                    dp[i][x][y]=max(dp[i][x][y],dp[i-1][x-1][y]+a[i][1]);
                if(y!=0)
                    dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y-1]+a[i][2]);
                if(x+y!=i)
                    dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y]+a[i][3]);
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int x=0;x<=n;x++)
        {
            for(int y=0;y<=n;y++)
                cout<<i<<" "<<x<<" "<<y<<" "<<dp[i][x][y]<<endl;
        }
    }*/
    int ans=0;
    for(int x=0;x<=n/2;x++)
    {
        for(int y=0;y<=n/2;y++)
        {
            if(x+y<n/2)
                continue;
            else
                ans=max(ans,dp[n][x][y]);
        }
    }
    cout<<ans<<endl;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        s2.insert(a[i][2]);
        s3.insert(a[i][3]);
    }
    if(n<=200)
        solvedp();
    else if(s2.size()==1 && s3.size()==1 && s2.count(0)==1 && s3.count(0)==1)
        solveA();
    else if(s3.size()==1 && s3.count(0)==1)
        solveB();
    else
        solvedp();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
