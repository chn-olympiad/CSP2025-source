#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],b[110],k;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    k=b[1];
    sort(b+1,b+n*m+1);
    int f=1,y[2]={1,n},x=0,c=n*m;
    for(int i=1;i<=m;i++)
    {
        for(int j=y[x];j>=1&&j<=n;j+=f)
        {
            a[j][i]=b[c];
            c--;
        }
        f*=-1;
        x=(x+1)%2;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==k)cout<<j<<' '<<i;
        }
    }
    return 0;
}
