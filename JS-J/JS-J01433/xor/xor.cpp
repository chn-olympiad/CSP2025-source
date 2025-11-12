#include <bits/stdc++.h>
using namespace std;
long long n, k, s, one, zero;
long long a[500010];
bool vis[500010];
bool xza, xzb;
long long x(long long l, long long r) {
        int sum = a[l];
        for(long long t = l + 1; t <= r; t++) {
            sum = (sum | a[t]) - (sum & a[t]);
        }
        return sum;
}
bool pas(long long l, long long r) {
        for(long long u = l; u <= r; u++) {
            if(vis[u] == false) {
                return false;
            }
        }
        return true;
}
void dfs(long long ans) {
    s = max(s, ans);
    for(long long i = 1; i <= n; i++) {
        for(long long j = i; j <= n; j++) {
            if(pas(i, j) == true && x(i, j) == k) {
                for(long long t = i; t <= j; t++) {
                    vis[t] = false;
                }
                dfs(ans + 1);
                for(long long t = i; t <= j; t++) {
                    vis[t] = true;
                }
            }
        }
    }
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    xza = true;
    xzb = true;
    if(k != 0) xza = false;
    if(k > 1) xzb = false;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
        vis[i] = true;
        if(a[i] != 1) xza = false;
        if(a[i] > 1) xzb = false;
        if(a[i] == 0) zero++;
        if(a[i] == 1) one++;
    }
    if(xza == true) {
        cout << n / 2 << endl;
        return 0;
    }
    if(xzb == true) {
        if(k == 0) {
            cout << zero + one / 2 << endl;
            return 0;
        } else {
            if(one > 0) {
                cout << max(zero, one) << endl;
            } else {
                cout << 0 << endl;
            }
            return 0;
        }
    }
    dfs(0);
    cout << s << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
