#include<bits/stdc++.h>
using namespace std;
int a[100001][4];int n;
int ans=0;
bool cmp(int x,int y)
{
    return x>y;
}
void solve1()
{
    int ans=0;
    int x[100001];
    for(int i=1;i<=n;i++)
        x[i]=a[i][1];
    sort(x+1,x+1+n,cmp);
    for(int i=1;i<=n/2;i++)
        ans+=x[i];
    cout<<ans;
    return ;
}
int dp[201][101][101];
int dfs(int now,int ai,int bi)
{
    //cout<<now<<" "<<n<<" "<<dp[now][ai]
    if(now>n)
        return 0;
    if(dp[now][ai][bi]!=-100)
        return dp[now][ai][bi];//cout<<"YES";
    int sum=0;
    if(ai<n/2)
    sum=max(sum,dfs(now+1,ai+1,bi)+a[now][1]);
    if(bi<n/2)
    sum=max(sum,dfs(now+1,ai,bi+1)+a[now][2]);
    if((now-ai-bi)<n/2)
    sum=max(sum,dfs(now+1,ai,bi)+a[now][3]);

    dp[now][ai][bi]=sum;
    return sum;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {cin>>n;
        for(int i=1;i<=n;i++)
            a[i][1]=a[i][2]=a[i][3]=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n/2;j++)
                for(int l=0;l<=n/2;l++)
                dp[i][j][l]=-100;

        ans=0;

        int sum2=0,sum3=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]==0)
            sum2++;
            if(a[i][3]==0)
            sum3++;
        }
        if(sum2==n&&sum3==n)
            {solve1();return 0;}
        //else
         //   if(sum3==n)
            //{solve2();return 0;}
        cout<<dfs(1,0,0)<<"\n";
      /*  for(int i=1;i<=n;i++)
        {
            cout<<"\n";
            for(int j=0;j<=n/2;j++)
            {
                for(int l=0;l<=n/2;l++)
                {
                    cout<<"i j k"<<i<<" "<<j<<" "<<l<<" "<<dp[i][j][l]<<" ";
                }
                cout<<"\n";
            }
        }
*/
    }
    return 0;
}
