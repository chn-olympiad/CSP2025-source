#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 5009;
int a[N], s[N], p[N], vst[N];

int n;
int cnt;

void dfs(int x, int c){
    if (x == n + 1){
        if (c >= 3){
            int mx = *max_element(p + 1, p + c + 1);
            int sm = 0;
            for (int i = 1; i <= c; i++){
                sm += a[p[i]];
                cout << a[p[i]] << ' ';
            }
            cout << '\n';
            if (sm > 2 * mx){
                cnt++;
                cnt %= MOD;
            }
            else return;
        }
        else return;
    }

    for (int i = x; i <= n; i++){
        p[c] = i;
        if (!vst[i]){
            vst[i] = 1;
            dfs(x + 1, c + 1);
        }
        vst[i] = 0;
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    dfs(1, 1);
    cout << cnt << '\n';
    return 0;
}