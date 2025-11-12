#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 107;
int n, m, tar, now, idx = 1, a[N], s[N][N];
bool cmp(int a, int b){
    return a > b;
}
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> a[i];
    tar = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int j = 1; j <= m; j++){
        now++;
        if(now & 1){
            for(int i = 1; i <= n; i++){
                s[j][i] = a[idx];
                idx++;
            }
        }else{
            for(int i = n; i >= 1; i--){
                s[j][i] = a[idx];
                idx++;
            }
        }
    }
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(s[j][i] == tar){
                cout << j << " " << i << '\n';
                return 0;
            }
        }
    }
    return 0;
}
