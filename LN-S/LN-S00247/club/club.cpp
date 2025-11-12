#include <bits/stdc++.h>
using namespace std;
int my[12][20086];
int num;
int dp[13][20087];
int book[3];
int sum[50000];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,i,j,k,o;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        num=0;
        o=n/2;
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=3;k++)
            {
                cin>>my[j][k];
            }
        }
        dp[1][1]=my[1][1];
        for(j=1;j<=3;j++)
        {
            for(k=1;k<=n;k++)
            {
                dp[j][k]=max(dp[j][k],dp[j-1][k]+my[i][k]);
                book[k]++;
                num++;
                sum[num]=dp[j][k];
                if(book[k]>o)
                {
                   sum[num]=0;
                }   
            }
        } 
       sort(sum+1,sum+1+num);
        cout <<sum[num]<< endl;
                 
    }
    
    return 0;
}
