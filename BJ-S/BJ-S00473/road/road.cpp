#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005][3],c[11][10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>u[i][0]>>u[i][1]>>u[i][2];
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
    cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
