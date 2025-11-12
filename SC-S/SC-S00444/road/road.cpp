#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+2;
long long n, m, k, a, b, c;
long long RG[maxn][maxn] = {0};
long long BG[maxn][maxn] = {0};
long long c_city[maxn] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    while(m--){
        cin >> a >> b >> c;
        RG[a][b] = c;
        RG[b][a] = c;
    }
    for(int j=0; j<k; j++){
        cin >> c_city[j];
        for(int i=1; i<=n; i++){
            cin >> BG[i][j];
            BG[j][i] = BG[i][j];
        }
    }
    return 0;
}