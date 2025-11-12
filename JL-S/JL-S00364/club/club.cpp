#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int T,n;
struct node
{
    int x[5];
    int mx;
    int p1,p2,p3;
}a[N];
int dp[N][5],sum[N][5][5];
bool cmp(node x,node y)
{
    //return x.x[x.p1]-x.x[x.p2]>y.x[y.p1]-y.x[y.p2];
    return x.mx>y.mx;
}
void f(int i)
{
    if(a[i].x[1]>=a[i].x[2] && a[i].x[1]>=a[i].x[3])
    {
        a[i].p1=1;
        if(a[i].x[2]>=a[i].x[3]) a[i].p2=2,a[i].p3=3;
        else a[i].p2=3,a[i].p3=2;
    }
    else if(a[i].x[2]>=a[i].x[1] && a[i].x[2]>=a[i].x[3])
    {
        a[i].p1=2;
        if(a[i].x[1]>=a[i].x[3]) a[i].p2=1,a[i].p3=3;
        else a[i].p2=3,a[i].p3=1;
    }
    else
    {
        a[i].p1=3;
        if(a[i].x[1]>=a[i].x[2]) a[i].p2=1,a[i].p3=2;
        else a[i].p2=2,a[i].p3=1;
    }
}
bool cmp2(node x,node y)
{
    return x.x[1]>y.x[1];
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>T;
    while(T--)
    {
        cin>>n;
        int flag=0;
        for(int i=1;i<=n;i++) cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3],a[i].mx=max(a[i].x[1],max(a[i].x[2],a[i].x[3]));
        for(int i=1;i<=n;i++)
        {
            if(a[i].x[2]!=0 || a[i].x[3]!=0) flag=1;
        }
        int maxx=n/2;
        if(n==2)
        {
            f(1);
            f(2);
            if(a[1].p1==a[2].p1)
            {
                if((a[1].x[a[1].p1]-a[1].x[a[1].p2]) > (a[2].x[a[2].p1]-a[2].x[a[2].p2])) cout<<a[1].x[a[1].p1]+a[2].x[a[2].p2]<<"\n";
                else cout<<a[1].x[a[1].p2]+a[2].x[a[2].p1]<<"\n";
            }
            else
            {
                cout<<a[1].x[a[1].p1]+a[2].x[a[2].p1]<<"\n";
            }
            continue;
        }
        if(flag==0)
        {
            sort(a+1,a+n+1,cmp2);
            cout<<a[1].x[1]+a[2].x[1]<<"\n";
            continue;
        }
        sort(a+1,a+n+1,cmp);
        memset(dp,0,sizeof dp);
        memset(sum,0,sizeof sum);
        dp[1][1]=a[1].x[1];
        dp[1][2]=a[1].x[2];
        dp[1][3]=a[1].x[3];
        sum[1][1][1]=sum[1][2][2]=sum[1][3][3]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                int cnt=0;
                for(int k=1;k<=3;k++)
                {
                    if(sum[i-1][k][j]+1<=maxx)
                    {
                        if(dp[i-1][k]+a[i].x[j]>=dp[i][j])
                        {
                            dp[i][j]=dp[i-1][k]+a[i].x[j];
                            cnt=k;
                        }
                    }
                }
                sum[i][j][1]=sum[i-1][cnt][1];
                sum[i][j][2]=sum[i-1][cnt][2];
                sum[i][j][3]=sum[i-1][cnt][3];
                sum[i][j][j]++;
            }
        }
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
    }
    return 0;
}
