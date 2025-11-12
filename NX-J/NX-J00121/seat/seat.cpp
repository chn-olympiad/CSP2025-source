#include<bits/stdc++.h>
using namespace std;
int n,m,z,s;
int a[11][11];
int b[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=0,z=0;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    int g=b[1];
    for(int j=1;j<=m*n;j++)
    {
        for(int i=j;i<=n*m-s;i++)
        {
            if(b[i]<b[i+1])
            {
                z=b[i+1];
                b[i+1]=b[i];
                b[i]=z;
            }
        }
        s++;
    }

    z=1;
    for(int i=1;i<=m,i++;)
    {
        for (int j=1;j<=n;j++)
        {
            a[j][i]=b[z];
            z++;
        }
        i++;
        for (int j=n;j>=1;j--)
        {
            a[j][i]=b[z];
            z++;
        }
    }
    for(int i=1;i<=m,i++;)
    {
        for (int j=1;j<=n;j++)
        {
            if(a[j][i]=g)
            {
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
