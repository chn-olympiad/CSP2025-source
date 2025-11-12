#include<bits/stdc++.h>
using namespace std;
int iii(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,d = 0;
    cin>>n>>m;
    int a[105];
    int b[15][15];
    int c = 0;
    for(int i = 0;i<m*n;i++)
    {
        cin>>a[i];
    }
    c=a[0];
    sort(a,a+m*n,iii);
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1,x=n;j<=n,x>=1;j++,x--)
        {
            if(i%2==1)
            {
                b[i][j]=a[d];
                d++;
            }
            else if(i%2==0)
            {
                b[i][x]=a[d];
                d++;
            }
        }
    }
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(b[i][j]==c)
            {
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
