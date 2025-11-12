#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int n,m;
int a[20];
int cnt=0;
int dis[20][20];
int st;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    st=a[1];
    sort(a+1,a+n*m+1);//100 99 98 97
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
        {
            for(int i=1;i<=n;i++)
            {
                dis[i][j]=a[n*m-(++cnt)+1];
            }
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                dis[i][j]=a[n*m-(++cnt)+1];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //cout<<dis[i][j]<<" ";
            if(dis[i][j]==st)
            {
                cout<<j<<" "<<i<<"\n";
                return 0;
            }
        }
        //cout<<"\n";
    }
    return 0;
}
