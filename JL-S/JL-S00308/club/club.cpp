#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int,int>PII;
const int N=310;
int t;
int n;
int dp[N][N][N];
int q[N][3];
void solve1()
{
    memset(dp,0,sizeof dp);
    dp[1][1][0]=q[1][0];dp[1][0][1]=q[1][1];dp[1][0][0]=q[1][2];
    for(int i=2;i<=n;i++)
        for(int a=0;a<=i;a++)
            for(int b=0;b<=i;b++)
            {
                if(a>n/2)continue;
                if(b>n/2)continue;
                int c=i-a-b;
                if(c>n/2)continue;
                if(a)dp[i][a][b]=max(dp[i][a][b],dp[i-1][a-1][b]+q[i][0]);
                if(b)dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b-1]+q[i][1]);
                if(c)dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b]+q[i][2]);
            }
    int res=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            int k=n-i-j;
            if(i>n/2||j>n/2||k>n/2)continue;
            res=max(res,dp[n][i][j]);
            // cout<<i<<' '<<j<<' '<<dp[n][i][j]<<endl;
        }
    cout<<res<<endl;
}
void solve2()
{
    int res=0;
    priority_queue<int>heap;
    for(int i=1;i<=n;i++)heap.push(q[i][0]);
    int cnt=n/2;
    while(cnt--)res+=heap.top(),heap.pop();
    cout<<res<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int A=1,B=1;
        for(int i=1;i<=n;i++)
            cin>>q[i][0]>>q[i][1]>>q[i][2];
        for(int i=1;i<=n;i++)
        {
            if(q[i][1]||q[i][2])A=0;
            if(q[i][2])B=0;
        }
        if(A)solve2();
        else solve1();

    }
    return 0;
}
