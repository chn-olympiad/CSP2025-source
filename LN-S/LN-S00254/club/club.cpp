#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
typedef pair<int,int> PII;

int T,n;
int a[N][4];
int ill[4][N][N];
int sum[4][N];
bool A=1,B=1;
bool used[N];

priority_queue <PII> q[4];



int ans;
int dp[N][4][N/2];

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%lld",&T);
    while(T--)
   {
       scanf("%lld",&n);

       for(int i=1;i<=n;i++)
       {
           scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][2]!=0||a[i][3]!=0) A=1;
            if(a[i][3]!=0) B=0;
             q[1].push({a[i][1],i});
             q[2].push({a[i][2],i});
             q[3].push({a[i][3],i});

       }
        if(A)
        {
            int arr=0;
            while(1)
            {
                ans+=q[1].top().first;
                q[1].pop();
                arr++;
                if(arr==n/2) break;
            }
            printf("%d\n",ans);
        }
        else{

            for(int kk=0;kk<=n/2;kk++)
            {
                for(int i=1;i<=n;i++)
                {
                        if(kk==0) 
                        {
                            dp[i][1][0]=dp[i][2][0]=dp[i][3][0]=0;
                        }
                        else
                        {

                        
                        dp[i][1][kk]=max(dp[i-1][1][kk-1]+a[i][1],dp[i][1][kk]);
                        dp[i][2][kk]=max(dp[i-1][2][kk-1]+a[i][2],dp[i][2][kk]);
                        dp[i][3][kk]=max(dp[i-1][3][kk-1]+a[i][3],dp[i][3][kk]);
                        for(int k1=0;k1+kk<=n;k1++)
                        {
                            int k2=n-k1-kk;
                        dp[i][1][kk]=max(max(dp[i-1][2][k1],dp[i-1][3][k2])+a[i][1],dp[i][1][kk]); 
                        dp[i][2][kk]=max(max(dp[i-1][1][k1],dp[i-1][3][k2])+a[i][2],dp[i][2][kk]);             
                        dp[i][3][kk]=max(max(dp[i-1][1][k1],dp[i-1][2][k2])+a[i][3],dp[i][3][kk]);
                        }
                        
                        }
          
                }
            }
            ans=0;
            for(int i=1;i<=3;i++)
               {
                   for(int kk=0;kk<=n/2;kk++)
                   {
                       ans=max(ans,dp[n][i][kk]);
                   }
               }
               printf("%d\n",ans);
        }

   }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


