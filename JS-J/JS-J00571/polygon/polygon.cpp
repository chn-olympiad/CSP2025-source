#include <bits/stdc++.h>
using namespace std;
const int N = 5005, M = 998244353;
int n, a[N];

bool special_max1;
int c[N][N];

bool bf_vis[N];
int bf_ans;

void Subtask1(){
    if(a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3]))) cout << 1;
    else cout << 0;
}

void dfs(int t){
    if(t > n){
        // Check if available.
        int check_sum = 0, check_max = 0;
        for(int i = 1; i <= n; ++i){
            if(bf_vis[i]){
                check_sum += a[i];
                check_max = max(check_max, a[i]);
            }
        }
        if(check_sum > 2 * check_max)
            bf_ans = (bf_ans + 1) % M;
        return;
    }
    bf_vis[t] = 1;
    dfs(t+1);
    bf_vis[t] = 0;
    dfs(t+1);
}
void Brute_force(){
    dfs(1);
    cout << bf_ans;
}

void C(){
    // C(n)(m) = C(n-1)(m) + C(n-1)(m-1)
    for(int i = 0; i < 5005; ++i) c[i][0] = 1;
    for(int i = 1; i <= 5004; ++i){
        for(int j = 1; j <= i; ++j){
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
        }
    }
}
void thanks_to_ccf(){
    // Calculate: C(n)(3) + C(n)(4) + C(n)(5) + ... + C(n)(n)
    C();
    int ans = 0;
    for(int i = 3; i <= n; ++i) ans = (ans + c[n][i]) % M;
    cout << ans;
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    special_max1 = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] != 1) special_max1 = 0;
    }
    if(n == 3) Subtask1();
    else if(n <= 20) Brute_force();
    else if(special_max1) thanks_to_ccf();
    return 0;
}
