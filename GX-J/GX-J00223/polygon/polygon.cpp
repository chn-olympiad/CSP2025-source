#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("poiygon.in","r",stdin);
    //freopen("priygon.out","w",stdout);
    int n,m,zs,w;
    cin>>n>>m;
    int a[11][11];
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            cin>>a[i][j];
        }
    }
    w=a[1][1];
    for(int j=1;j<m+1;j++)
    {
        for(int i=1;i<n+1;i++)
        {
            if(a[i][j]<a[i+1][j])
            {
                zs=a[i][j];
                a[i][j]=a[i+1][j];
                a[i+1][j]=zs;
            }
        }
    }
    for(int j=1;j<m+1;j++)
    {
        for(int i=1;i<n+1;i++)
        {
            if(a[i][j]=w )
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
}
