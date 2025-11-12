#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],mp[15][15],vis[15][15];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                mp[i][j]=a[(i-1)*n+j];
            }
        }else{
            for(int j=n;j>=1;j--)
            {
                mp[i][j]=a[i*n-j+1];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==r)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
