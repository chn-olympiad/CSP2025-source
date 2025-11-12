#include<bits/stdc++.h>

using namespace std;

const int N = 505;
const long long mod = 998244353;
int n, m;
string s;
int a[N];
int ind[N];

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ind[i] = i;
    }
    if (n <= 10) {
        long long ans = 0;
        do {
            int t = 0, t2 = 0;
            for (int i = 1; i <= n; i++) {
                if (t2 >= a[ind[i]] || !(s[i] - '0')) t2++;
            }
            ans = (ans + (n - t2 >= m)) % mod;
        } while(next_permutation(ind + 1, ind + n + 1));
        cout << ans;
        return 0;
    }
    if (m == 1) {
        int flag = 0;
        for (int i = 1; i <= n; i++) if (s[i]) flag = i;
        if (!flag) {
            cout << 0;
            return 0;
        }
        long long res = 1;
        for (int i = 1; i <= n - 1; i++) res = (res * i) % mod;
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += (a[i] >= flag);
        cout << ((long long)cnt * res) % mod;
        return 0;
    }
    if (m == n) {
        bool flag = true;
        for (int i = 1; i <= n; i++) if (!s[i]) flag = false;
        if (!flag) {
            cout << 0;
            return 0;
        }
        for (int i = 1; i <= n; i++) if (!a[i]) flag = false;
        if (!flag) {
            cout << 0;
            return 0;
        }
        long long res = 1;
        for (int i = 1; i <= n; i++) res = (res * i) % mod;
        cout << res;
        return 0;
    }
  return 0;
}