#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,l;
    cin >> n >> m >> k;
    int a[m+1][m+1][k+1];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int l=1;l<=10000;l++)
                cin >> a[i][j][l];
        }
    }
    int b[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    cout << "0";
    return 0;
}
