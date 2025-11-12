#include<iostream>
using namespace std;
int n,t;
int myd[203][5],my[103][103][103];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>t;
    for(T=1;T<=t;T++)
    {
        int i,j,k;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=3;j++)
            {
                cin>>myd[i][j];
            }
        }
        for(i=0;i<=n/2;i++)
        {
            for(j=0;j<=n/2;j++)
            {
                for(k=0;k<=n/2;k++)
                {
                    my[i][j][k]=0;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<i && j<=n/2;j++)
            {
                for(k=0;k<i-j && k<=n/2;k++)
                {
                    if(i-j-k-1<=n/2)
                    {
                        //cout<<my[j][k][i-j-k]<<" "<<my[j][k+1][i-j-k-1]<<" "<<my[j+1][k][i-j-k-1]<<endl;
                        my[j][k][i-j-k]=max(my[j][k][i-j-k],my[j][k][i-j-k-1]+myd[i][3]);
                        my[j][k+1][i-j-k-1]=max(my[j][k+1][i-j-k-1],my[j][k][i-j-k-1]+myd[i][2]);
                        my[j+1][k][i-j-k-1]=max(my[j+1][k][i-j-k-1],my[j][k][i-j-k-1]+myd[i][1]);
                        //cout<<i<<" "<<j<<" "<<k<<" "<<i-j-k-1<<" "<<my[j][k][i-j-k-1]<<endl;
                    }
                }
            }
        }
        i=0;
        for(j=0;j<=n/2;j++)
        {
            for(k=n/2-j;k<=n/2;k++)
            {
                if(my[j][k][n-j-k]>i)
                {
                    i=my[j][k][n-j-k];
                }
            }
        }
        cout<<i<<endl;
    }
    return 0;
}
