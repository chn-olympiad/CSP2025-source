#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[1000000][4];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=3;j++){
            cin >> v[i][j];
        }
    }
    long long minn = 0x7FFFFF;
    for(int i = 1;i<=n/2;i++){
        v[i][2] = min(v[i+1][2],v[i][2]);

    }
    int ans = 0;
    for(int i = 1;i<=n/2;i++){
        ans+=v[i][2];
    }
    cout << ans;
    return 0;
}
