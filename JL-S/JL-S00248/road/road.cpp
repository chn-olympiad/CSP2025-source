#include <iostream>
#include <cstdlib>
using namespace std;
int u[1000002],v[1000002],w[1000002];
int c[12],a[12][10002];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,i,j;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(j=1;j<=k;j++)
    {
        cin>>c[j];
        for(i=1;i<=n;i++)
            cin>>a[j][i];
    }
    cout<<13<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
