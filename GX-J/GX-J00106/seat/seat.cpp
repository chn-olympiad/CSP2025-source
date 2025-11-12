#include<iostream>
#include<algorithm>
using namespace std;
long long a[11][11],b[506];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long j,n,m,i,k,p,v;
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
        cin>>b[i];
        k=b[1];
        v=n*m;
        p=n*m;
    sort(b+1,b+v+1);
    for(i=1;i<=m;i++)
    {
    for(j=1;j<=n&&p>=1;j++)
    {a[j][i]=b[p];p--;}
    i++;
    for(j=n;j>=1&&i<=m&&p>=1;j--)
        {a[j][i]=b[p];p--;}
    }
     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j]==k){cout<<j<<" "<<i;break;}
    return 0;
}
