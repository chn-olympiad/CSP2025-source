#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, a[N];
bool cmp(int a, int b){
    return a > b;
}
void solve1(){
    int a[3][4];
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= 3; j++){
            cin >> a[i][j];
        }
    }
    int mx = max({a[1][1] + a[2][2], a[1][1] + a[2][3], a[1][2] + a[2][1], a[1][2] + a[2][3], a[1][3] + a[2][1], a[1][3] + a[2][2]});
    cout << mx << '\n';
}
void solve(){
    cin >> n;
    if(n == 2){
        solve1();
        return;
    }
    int a[3 * n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            int x;
            cin >> x;
            a[(i - 1) * 3 + j] = x;
        }
    }
    int sum = 0;
    sort(a + 1, a + 3 * n + 1, cmp);
    for(int i = 1; i <= n / 2; i++){
        sum += a[i];
    }
    cout << sum << "\n";
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
