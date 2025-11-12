#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);


    int n,m;
    cin>>n>>m;
    int a[m][n];    //BuYaoGai!!!!!!!!!!
    int b[m*n],c[m*n];
    for(int i=0;i<m*n;i++) cin>>b[i];

    int ms=b[0];  //FenShu

    int x=0;
    for(int i=0;i<n*m;i++)
    {
        int max=0;
        int y=-1;
        for(int j=0;j<n*m;j++)
        {
            if(b[j]>=max)
            {
                max=b[j];
                y=j;
            }
        }
        b[y]=-1;
        c[x]=max;
        x++;
    }



memset(a,0,sizeof(a));


    int bp=1;
    int sy=0;
    for(int i=0;i<m;i++)
    {

        if(bp%2==1)
            for(int j=0;j<n;j++)
            {
                a[j][i]=c[sy];
                sy++;
            }
        if(bp%2==0)
            for(int j=0;j<n;j++)
            {
                a[n-j-1][i]=c[sy];
                sy++;
            }
        bp++;
    }

    int mx,my;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==ms)
            {
                mx=j+1;my=i+1;
            }
        }
    }
    cout<<mx<<' '<<my<<endl;
    return 0;
}
