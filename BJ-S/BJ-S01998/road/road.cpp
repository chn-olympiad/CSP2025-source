#include<iostream>
#define int long long
using namespace std;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int s = 0, n, m, k, u[100005], v[100005], w[100005],c[15], a[15][10005],tmp[100005] = {0};
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i = 0; i < k; i++){
        cin >> c[i];
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        if(tmp[i] = 0){
            for(int j = 0; j < n; j++){
                if(u[i] == i || v[i] == i){
                    s+=w[i];
                }
            }
        }
    }
    cout << s;
    return 0;
}
