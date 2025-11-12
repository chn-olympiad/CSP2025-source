#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005][5],dp[100005][5];
int c[10005][5];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        for(int i=1; i<=m;i++)
        {
            for(int j=1; j<=3; j++)
            {
                cin>>a[i][j];
                dp[i][j]=a[i][j];
            }
        }
        int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0;
        for(int i=2; i<=m+2; i++)
        {
            for(int j=1; j<=3; j++)
            {
                 if(i==m+1) x1=0,x2=0,x3=0,y1=0,y2=0,y3=0;
                if(c[x1][y1]+1<m/2 && c[x2][y2]+1<m/2 && c[x3][y3]+1<m/2)
                {
                    if(j==1){
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j+1]+dp[i][j]),dp[i-1][j+2]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x1=i-1,y1=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j+1]+x) x1=i-1,y1=j+1,c[i][j]=c[i-1][j+1]+1;
                            else x1=i-1,y1=j+2,c[i][j]=c[i-1][j+2];
                    }
                    else if(j==2)
                    {
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j-1]+dp[i][j]),dp[i-1][j+1]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x2=i-1,y2=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j-1]+x) x2=i-1,y2=j-1,c[i][j]=c[i-1][j-1]+1;
                            else x2=i-1,y2=+1,c[i][j]=c[i-1][j+1]+1;
                    }
                    else {
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j-1]+dp[i][j]),dp[i-1][j-2]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x3=i-1,y3=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j-1]+x) x3=i-1,y3=j-1,c[i][j]=c[i-1][j-1]+1;
                            else x3=i-1,y3=j-2,c[i][j]=c[i-1][j-2]+1;
                    }
                }
                else if(c[x1][y1]+1<m/2 && c[x2][y2]+1<m/2)
                {
                    if(j==1){
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j+1]+dp[i][j]),dp[i-1][j+2]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x1=i-1,y1=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j+1]+x) x1=i-1,y1=j+1,c[i][j]=c[i-1][j+1]+1;
                            else x1=i-1,y1=j+2,c[i][j]=c[i-1][j+2];
                    }
                    else if(j==2)
                    {
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j-1]+dp[i][j]),dp[i-1][j+1]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x2=i-1,y2=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j-1]+x) x2=i-1,y2=j-1,c[i][j]=c[i-1][j-1]+1;
                            else x2=i-1,y2=+1,c[i][j]=c[i-1][j+1]+1;
                    }
                }
                else if(c[x1][y1]+1<m/2 && c[x3][y3]+1<m/2)
                {
                    if(j==1){
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j+1]+dp[i][j]),dp[i-1][j+2]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x1=i-1,y1=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j+1]+x) x1=i-1,y1=j+1,c[i][j]=c[i-1][j+1]+1;
                            else x1=i-1,y1=j+2,c[i][j]=c[i-1][j+2];
                    }
                    else if(j==3){
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j-1]+dp[i][j]),dp[i-1][j-2]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x3=i-1,y3=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j-1]+x) x3=i-1,y3=j-1,c[i][j]=c[i-1][j-1]+1;
                            else x3=i-1,y3=j-2,c[i][j]=c[i-1][j-2]+1;
                    }
                }
                else if(c[x2][y2]+1<m/2 && c[x3][y3]+1<m/2)
                {
                    if(j==2)
                    {
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j-1]+dp[i][j]),dp[i-1][j+1]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x2=i-1,y2=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j-1]+x) x2=i-1,y2=j-1,c[i][j]=c[i-1][j-1]+1;
                            else x2=i-1,y2=+1,c[i][j]=c[i-1][j+1]+1;
                    }
                    else if(j==3){
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j-1]+dp[i][j]),dp[i-1][j-2]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x3=i-1,y3=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j-1]+x) x3=i-1,y3=j-1,c[i][j]=c[i-1][j-1]+1;
                            else x3=i-1,y3=j-2,c[i][j]=c[i-1][j-2]+1;
                    }
                }
                else if(c[x1][y1]+1<m/2)
                {
                    if(j==1){
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j+1]+dp[i][j]),dp[i-1][j+2]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x1=i-1,y1=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j+1]+x) x1=i-1,y1=j+1,c[i][j]=c[i-1][j+1]+1;
                            else x1=i-1,y1=j+2,c[i][j]=c[i-1][j+2];
                    }
                }
                else if(c[x2][y2]+1<m/2)
                {
                     if(j==2)
                    {
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j-1]+dp[i][j]),dp[i-1][j+1]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x2=i-1,y2=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j-1]+x) x2=i-1,y2=j-1,c[i][j]=c[i-1][j-1]+1;
                            else x2=i-1,y2=j+1,c[i][j]=c[i-1][j+1]+1;
                    }
                }
                else if(c[x3][y3]+1<m/2)
                {

                    if(j==3){
                            int x=dp[i][j];
                            dp[i][j]=max(max(dp[i-1][j]+dp[i][j],dp[i-1][j-1]+dp[i][j]),dp[i-1][j-2]+dp[i][j]);
                            if(dp[i][j]==dp[i-1][j]+x) x3=i-1,y3=j,c[i][j]=c[i-1][j]+1;
                            else if(dp[i][j]==dp[i-1][j-1]+x) x3=i-1,y3=j-1,c[i][j]=c[i-1][j-1]+1;
                            else x3=i-1,y3=j-2,c[i][j]=c[i-1][j-2]+1;
                    }
                }
                else dp[i][j]=dp[i-1][j];

            }
        }
        cout<<dp[m+1][1]<<endl;
    }
    return 0;
}

