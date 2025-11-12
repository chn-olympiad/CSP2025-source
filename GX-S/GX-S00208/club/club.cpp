# include <bits/stdc++.h>
# define MAXN 100005

using namespace std;

struct num{int a;int b;int c;};
struct num arr[MAXN];

int dp[205][105][105];
//到第i个人两个社团i和j个人
int ans[205];

void sovle()
{
    int n;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf ("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].c);
    }
    int ans=0;

    dp[1][1][0] = arr[1].a;

    dp[1][0][1] = arr[1].b;
    dp[1][0][0] = arr[1].c;

    for (int i=2;i<=n;i++)  //当前人数
    {
        for (int j=0;j<=n/2;j++)  // 第一个社团的人数
        {
            for (int k=0;k<=n/2;k++) // 第二个社团的人数
            {
                if (i-(j+k) > n/2) continue;
                dp[i][j][k] = max((dp[i-1][j-1][k]+arr[i].a)*(j>0),max(dp[i-1][j][k-1]+arr[i].b*(k>0),dp[i-1][j][k]+arr[i].c*(i-(j+k)>0))); // 加入第一个
            }
        }
    }

    for (int j=0;j<=n/2;j++)
    {
        for (int k=0;k<=n/2;k++)
        {
            if (n-(j+k) > n/2) continue;
            ans = max(dp[n][j][k],ans);
        }
    }

    printf ("%d\n",ans);

    return ;
}

int main (void)
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf ("%d",&T);

    while (T--)
    {
        sovle();
    }

    return 0;
}

