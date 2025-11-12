#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 19, M = 4e6;
const long long mod = 998244353;

int n, m, k;
int p[N], g, death;
long long ans;
string s;
bool v[N];
void dfs_baoli(int u, int d){
    if (d == n)
        if(n - death >= m)
            ans++;
    for (int i = 1; i <= n; i++){
        if(v[i]) continue;
        if(s[d] == '0'|| death >= p[i])
            death++;
        v[i] = 1;
        dfs_baoli(i, d + 1);
        v[i] = 0;
        if(s[d] == '0'|| death >= p[i])
            death--;
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    if (n <= 10){
        dfs_baoli(0, 0);
        cout << ans % mod;
        return 0;
    }
    if (m == n){
        for (int i = 0; i < n; i++)
            if(s[i] == '0' || p[i + 1] == 0){
                cout << 0;
                return 0;
            }
        ans = 1;
        for (int i = 1; i <= n; i++)
            (ans *= i) %= mod;
        cout << ans;
        return 0;
    }
    return 0;
}
