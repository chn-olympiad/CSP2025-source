#include<bits/stdc++.h>
using namespace std;
int a[100010][4], f[100010], dp[40][25][25][25];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n, xmax;
        cin>>n;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0)
                flag=false;
        }
        if(flag&&n!=0)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                f[i]=a[i][1];
            }
            sort(f+1, f+n+1);
            for(int i=n;i>=n/2+1;i--)
            {
                sum+=f[i];
            }
            cout<<sum<<endl;
            continue;
        }
        memset(dp, -0x3f, sizeof(dp));
        dp[1][1][0][0]=a[1][1];
        dp[1][0][1][0]=a[1][2];
        dp[1][0][0][1]=a[1][3];
        xmax=max({a[1][1], a[1][2], a[1][3]});
        for(int i=2;i<=n;i++)
        {
            for(int j1=0;j1<=n/2;j1++)
            {
                for(int j2=0;j2<=n/2;j2++)
                {
                    for(int j3=0;j3<=n/2;j3++)
                    {
                        dp[i][j1][j2][j3]=max({dp[i-1][j1-1][j2][j3]+a[i][1], dp[i-1][j1][j2-1][j3]+a[i][2], dp[i-1][j1][j2][j3-1]+a[i][3]});
                        xmax=max(xmax, dp[i][j1][j2][j3]);
                    }
                }
            }
        }
        cout<<xmax<<endl;
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
