#include <bits/stdc++.h>
using namespace std;
const int N=1e5+4;
const int M=200+5;
int n;
int a[N][5];
int dp[M][M][M];
int box[N];
long long ans=0;
void dfs(int cur,long long sum)
{
    if(cur>n)
    {
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++)
        {
            if(box[i]==1) cnt1++;
            if(box[i]==2) cnt2++;
            if(box[i]==3) cnt3++;
        }
        if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2) ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        box[cur]=i;
        dfs(cur+1,sum+a[cur][i]);
    }
}
bool check(int i,int x,int y,int z)
{
    return (x<=i/2 && y<=i/2 && z<=i/2 && x>=0 && y>=0 && z>=0);
}
void solve()
{
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++) cin >>a[i][j];
    }
    ans=0;
    dfs(1,0);
    cout <<ans<<'\n';
    /*
    for(int i=1;i<=n;i++)
    {
        dp[2][1][1]=max(a[1][1]+a[2][2] , a[1][2]+a[2][1]);
        dp[2][1][0]=max(a[1][1]+a[2][3] , a[1][3]+a[2][1]);
        dp[2][0][1]=max(a[1][2]+a[2][3] , a[1][3]+a[2][2]);
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<=i/2;j++)
        {
            for(int k=0;k<=i/2;k++)
            {
                int l=i-j-k;
                if(l<=i/2)
                {
                    int x=0,y=0,z=0,xx=0,yy=0,zz=0,d=0,e=0,f=0;
                    if(check(i-1,j-1,k,l)) x=dp[i-1][j-1][k]+a[i][1];
                    if(check(i-1,j,k-1,l)) y=dp[i-1][j][k-1]+a[i][2];
                    if(check(i-1,j,k,l-1)) z=dp[i-1][j][k]+a[i][3];
                    if(check(i-2,j-1,k-1,l)) xx=dp[i-2][j-1][k-1]+max(a[i-1][1]+a[i][2] , a[i-1][2]+a[i][1]);
                    if(check(i-2,j-1,k,l-1)) yy=dp[i-2][j-1][k]+max(a[i-1][1]+a[i][3] , a[i-1][3]+a[i][1]);
                    if(check(i-2,j,k-1,l-1)) zz=dp[i-2][j][k-1]+max(a[i-1][2]+a[i][3] , a[i-1][3]+a[i][2]);
                    if(check(i-2,j-2,k,l)) d=dp[i-2][j-2][k]+a[i-1][1]+a[i][1];
                    if(check(i-2,j,k-2,l)) e=dp[i-2][j][k-2]+a[i-1][2]+a[i][2];
                    if(check(i-2,j,k,l-2)) f=dp[i-2][j][k]+a[i-1][3]+a[i][3];
                    dp[i][j][k]=max(max(max(max(max(max(max(max(x,y),z),xx),yy),zz),d),e),f);
                }
            }
        }
    }
    for(int x=1;x<=n;x++)
    {
        for(int i=0;i<=x/2;i++)
        {
            for(int j=0;j<=x/2;j++)
            {
                int k=x-i-j;
                if(check(x,i,j,k))
                {
                    //cout <<"DP["<<x<<"]["<<i<<"]["<<j<<"]=";
                    //cout <<dp[x][i][j]<<'\n';
                }
            }
        }
    }
    int maxx=0;
    for(int i=0;i<=n/2;i++)
    {
        for(int j=0;j<=n/2;j++)
        {
            int k=n-i-j;
            if(k<=n/2) maxx=max(maxx,dp[n][i][j]);
        }
    }
    cout <<maxx<<'\n';
    */
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    while(t--) solve();
    return 0;
}
