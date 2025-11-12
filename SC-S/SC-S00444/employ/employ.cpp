#include<bits/stdc++.h>
using namespace std;

long long n, m, s;
int naixin[505] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    cin >> s;
    for(int i=1; i<=n; i++) cin >> naixin[i];
    long long ans = 1;
    for(int i=1; i<=n; i++){
        ans *= i;
        ans %= 998244353;
    }
    for(int i=1; i<=m; i++){
        ans /= i;
        ans %= 998244353;
    }
    cout << ans;
    return 0;
}