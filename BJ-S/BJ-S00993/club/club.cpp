#include<bits/stdc++.h>
using namespace std;
int a[100010][10];
int f[1010][1010][4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("clab.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    f[i][j][k]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int z=min(i-1,m);
                for(int k=1;k<=3;k++)
                {
                    f[i][j][k]=max({f[i-1][j-1][k],f[i-1][z][k%3+1],f[i-1][z][(k%3+1)%3+1]})+a[i][k];
                }
            }
        }
        cout<<max({f[n][m][1],f[n][m][2],f[n][m][3]})<<"\n";
    }
}