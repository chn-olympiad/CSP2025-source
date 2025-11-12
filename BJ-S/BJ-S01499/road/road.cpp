#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u[100010][5],v[20][10],ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u[i][1]>>u[i][2]>>u[i][3];
    for(int i=1;i<=k;i++)
    {
        cin>>v[i][1];
        for(int j=1;j<=n;j++) cin>>v[i][j+1];
    }
    for(int i=1;i<=m;i++) ans+=u[i][3];
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}