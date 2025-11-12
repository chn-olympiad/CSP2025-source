#include<bits/stdc++.h>

using namespace std;

int t,n;
int a[10000],b[10000],c[10000];
int f[10000][10000];


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;

    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            /*aq[i]=aq[i-1]+a[i];
            bq[i]=bq[i-1]+b[i];
            cq[i]=cq[i-1]+c[i];*/
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
             {
                 f[i][j]=max(f[i-1][j],max(f[i-1][j-1]+a[i],max(f[i-1][j-1]+b[i],f[i-1][j-1]+c[i])));

             }

        }
        cout<<f[n][n]<<endl;
    }
    return 0;
}
