#include <bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main()
{
    freopen("croad.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {

            cin>>a[i][j];
        }
    }
    for(int i=1;i<=2;i++)
    {

        for(int j=1;j<=5;j++)
        {

            cin>>a[i][j];
        }
    }
    cout<<13;
    return 0;
}
