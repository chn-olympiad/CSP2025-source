#include<bits/stdc++.h>
using namespace std;
int dp[5][100005];
struct Ry
{
    int rx=0;
    int g1,g2,g3;
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("clud.out","w",stdout);

    int t;
    cin>>t;
    for(int zs=1;zs<=t;zs++)
    {
        int n;
        cin>>n;
        Ry yuangong[n];
        int book[5]={0,0,0,0,0};
        for(int i=1;i<=n;i++)
        {
            cin>>yuangong[i].g1>>yuangong[i].g2>>yuangong[i].g3;
        }
        dp[1][1]=yuangong[1].g1;
        dp[2][1]=yuangong[1].g2;
        dp[2][1]=yuangong[1].g2;
        for(int i=2;i<=n;i++)
        {
            int _max;
            if(dp[1][i-1]>dp[2][i-1]&&dp[1][i-1]>dp[3][i-1])
            {
                book[1]++;
                _max=dp[1][i-1];
            }
            else if(dp[2][i-1]>dp[1][i-1]&&dp[2][i-1]>dp[3][i-1])
            {
                book[2]++;
                _max=dp[2][i-1];
            }
            else if(dp[3][i-1]>dp[1][i-1]&&dp[3][i-1]>dp[2][i-1])
            {
                book[3]++;
                _max=dp[3][i-1];
            }





            if(book[1]+1<=n/2)
            {
                dp[1][i]=dp[1][i-1]+yuangong[i].g1;
                //cout<<dp[1][i]<<" ";
            }
            else
            {
                dp[1][i]=dp[1][i-1];
            }
            if(book[2]+1<=n/2)
            {
                dp[2][i]=_max+yuangong[i].g2;
              //  cout<<dp[2][i]<<" ";
            }
            else
            {
                dp[2][i]=_max;
            }
            if(book[3]+1<=n/2)
            {
                dp[3][i]=_max+yuangong[i].g3;
              //  cout<<dp[3][i]<<" ";
            }
            else
            {
                dp[3][i]=_max;
            }






           // cout<<endl;
        }
      //  cout<<dp[1][n]<<" "<<dp[2][n]<<" "<<dp[3][n];
        cout<<max(max(dp[1][n],dp[2][n]),dp[3][n])<<endl;
    }

    return 0;
}
