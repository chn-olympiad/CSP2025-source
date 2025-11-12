#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],ai,len;
int xy[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    ai=a[1],len=n*m+1;
    for(int i=2;i<=n*m;i++)
        cin>>a[i];
    sort(a+1,a+1+n*m);
    for(int j=1;j<=m/2;j++)
    {
        for(int i=1;i<=n;i++)
            xy[i][j*2-1]=a[--len];
        for(int i=n;i>=1;i--)
            xy[i][j*2]=a[--len];
    }
    if(m%2==1)
        for(int i=1;i<=n;i++)
            xy[i][m]=a[--len];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(xy[i][j]==ai)
            {
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
