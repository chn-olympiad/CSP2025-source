#include <bits/stdc++.h>
using namespace std;
int xx[15][15],n,m,a[105];
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
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int s=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                xx[i][j]=a[s];
                if(a[s]==t)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                s++;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                xx[i][j]=a[s];
                if(a[s]==t)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                s++;
            }
        }
    }
    return 0;
}
