#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[101000],v[101000],w[101000],c[101000],a[15][11000],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin >> c[i];
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    sort(w+1,w+m+1);
    for(int i=1;i<=m-k;i++)
    {
        ans+=w[i];
    }
    cout << ans;
    return 0;
}
