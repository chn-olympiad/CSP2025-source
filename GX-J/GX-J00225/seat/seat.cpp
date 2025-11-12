#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b[122];
    int a[11][11],i,j,c=1,k;
    cin>>n>>m;
    for(i=0;i<m*n;++i)
    {
        cin>>b[i];
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            if(b[c]>b[0])
            {
                a[i][j]=b[c];
                c++;
            }
            else
            {
                cout<<i+1<<" "<<j+1;
                return 0;
            }
        }
        for(j=m;j>0;--j)
        {
            if(b[c]>b[0])
            {
                a[i][j]=b[c];
                c++;
            }
            else
            {
                cout<<i+1<<" "<<j+1;
            }
        }
    }
    return 0;
}
