#include<bits/stdc++.h>
using namespace std;
int iin[100];
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int max(int a,int b,int c)
{
    if(a>b&&a>c)return a;
    else if(b>a&&b>c)return b;
    else return c;
}
struct student
{
    int a[4];
};
int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        int n;
        int dp[100000][4]={0};
        int g[4]={0};
        student s[10000];
        cin >> n;
        int mid=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(g[j]==mid)
                {
                    dp[i][j]=max(dp[g[j]-1][j]+s[i].a[j],dp[i-1][j],dp[i][j]);
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j]+s[i].a[j],dp[i][j-1]);
                    if(dp[i][j]==dp[i-1][j]+s[i].a[j]&&dp[i][j]!=dp[i][j-1])
                    {
                        g[j]++;
                    }
                }

            }
        }
        iin[i]=dp[n][3]+dp[n][2]+dp[n][1];
    }
    for(int i=0;i<t;i++)
    {
        cout << iin[i]/2 << endl;
    }
    return 0;
}
