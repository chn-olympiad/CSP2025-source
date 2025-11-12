#include <bits/stdc++.h>
using namespace std;
long long n, i, j, s;
long long a[5010];
void dfs(long long u, long long sum, long long maxn) {
        if(u == n) {
            if(sum > maxn * 2) {
                s++;
                return ;
            }
        } else {
            dfs(u + 1, (sum + a[u + 1]) % 998244353, max(maxn, a[u + 1]));
            dfs(u + 1, sum % 998244353, maxn);
        }
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << s << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
