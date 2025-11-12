#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10][10],b[100],c[100][100];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);


    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            b[i]=a[i][j];
            c[i][j]=b[i];
        }
    }
    sort(b,b+n*m);
    if(a[1][1]==100)
    {
        cout<<1<<' '<<1;
        return 0;
    }
    else
    {
        for(int i=1;i<=m;++i)
        {
            if(i%2!=0)
            {
                for(int j=1;j<=n;j++)
                {
                    a[i][j]=b[i];
                    if(b[i]=c[1][1])
                    {
                        cout<<i<<' '<<j;
                    }
                }
            }
            else
            {
                for(int k=n;k>=1;--k)
                {
                    a[i][k]=b[i];
                    if(b[i]==c[1][1])
                    {
                        cout<<i<<' '<<k;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;


    fclose(stdin);
    fclose(stdout);
}
