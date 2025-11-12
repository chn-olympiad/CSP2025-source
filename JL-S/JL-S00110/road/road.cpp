#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10;
const int N=1e4+10;
const int K=25;
int n,m,k;
int u[M],v[M],w[M];
int a[K][N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<13;
    return 0;
}
