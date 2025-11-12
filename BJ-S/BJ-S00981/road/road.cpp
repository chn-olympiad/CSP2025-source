#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[110],v[110],w[110],a[1010][110],a1[110],b1[110],num;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            b1[i] = a[i][j];
        }
    }
    sort(w+1,w+m+1);
    sort(a+1,a+k+1);
    for(int i=1;i<=n;i++){
        a1[i] = w[i];
    }
    for(int i=1;i<=n;i++){
        num += a1[i];
    }
    for(int i=1;i<=n;i++){
        num += b1[i];
    }
    cout << num;
    return 0;
}
