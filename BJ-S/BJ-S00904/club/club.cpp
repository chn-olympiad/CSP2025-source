#include<bits/stdc++.h>
using namespace std;
long long t;
long long a[100010][5];
long long b[100010][5];
long long c[100010][5][5];
int main()
{
   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int tmm=1;tmm<=t;tmm++)
    {
        long long n,m,ans=0;
        cin>>n;
        m=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                long long s=-1,t=0;
                for(int k=1;k<=3;k++)
                {
                    if(b[i-1][k] > s)
                    {
                        if(c[i-1][k][j]+1 <= m)
                        {
                            s=b[i-1][k];
                            t=k;
                        }
                    }
                }
                b[i][j]=s+a[i][j];
                c[i][j][1]=c[i-1][t][1];
                c[i][j][2]=c[i-1][t][2];
                c[i][j][3]=c[i-1][t][3];
                c[i][j][j]++;
               // cout<<b[i][j]<<' ';
            }
           // cout<<endl;
        }
        for(int i=1;i<=3;i++)
        {
            ans=max(ans,b[n][i]);
         //   cout<<b[n][i]<<' ';
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                a[i][j]=b[i][j]=0;
                c[i][j][1]=c[i][j][2]=c[i][j][3]=0;
            }
        }
    }
    return 0;
}