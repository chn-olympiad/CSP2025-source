#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],sum[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>sum[i];
    }
    int p=sum[1];
    sort(sum+1,sum+n*m+1);
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if(i%2==1) a[j][i]=sum[k--];
            else a[n-j+1][i]=sum[k--];
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if(a[i][j]==p)
            {
                cout<<j<<" "<<i<<endl;
                return 0;
            }
        }
    }
}
