#include <bits/stdc++.h>
using namespace std;

const long long mod[2] = {998244353, (long long)1e9 + 7};
int n, q;
long long u[2][200005], v[2][200005], L[2][200005], R[2][200005];
int lenl[200005], lenr[200005];
long long U[2], V[2], ll[2][5000005], rr[2][5000005];
int ans;
string s1, s2;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        int le = s1.size();
        int l = 0, r = le - 1;
        while (l <= r && s1[l] == s2[l]) l++;
        if (l > r) continue;
        while (s1[r] == s2[r]) r--;
        for (int j = l; j <= r; j++) {
            u[0][i] = (u[0][i] * 26 + s1[j] - 'a') % mod[0];
            u[1][i] = (u[1][i] * 26 + s1[j] - 'a') % mod[1];
            v[0][i] = (v[0][i] * 26 + s2[j] - 'a') % mod[0];
            v[1][i] = (v[1][i] * 26 + s2[j] - 'a') % mod[1];
        }
        for (int j = l - 1; j >= 0; j--) {
            L[0][i] = (L[0][i] * 26 + s1[j] - 'a') % mod[0];
            L[1][i] = (L[1][i] * 26 + s1[j] - 'a') % mod[1];
        }
        for (int j = r + 1; j < le; j++) {
            R[0][i] = (R[0][i] * 26 + s1[j] - 'a') % mod[0];
            R[1][i] = (R[1][i] * 26 + s1[j] - 'a') % mod[1];
        }
        lenl[i] = l;
        lenr[i] = le - r - 1;
    }
    while (q--) {
        cin >> s1 >> s2;
        ans = 0;
        int le = s1.size();
        int l = 0, r = le - 1;
        while (s1[l] == s2[l]) l++;
        if (l > r) continue;
        while (s1[r] == s2[r]) r--;
        U[0] = U[1] = 0;
        V[0] = V[1] = 0;
        for (int j = l; j <= r; j++) {
            U[0] = (U[0] * 26 + s1[j] - 'a') % mod[0];
            U[1] = (U[1] * 26 + s1[j] - 'a') % mod[1];
            V[0] = (V[0] * 26 + s2[j] - 'a') % mod[0];
            V[1] = (V[1] * 26 + s2[j] - 'a') % mod[1];
        }
        ll[0][0] = ll[1][0] = 0;
        rr[0][0] = rr[1][0] = 0;
        for (int j = l - 1; j >= 0; j--) {
            ll[0][l - j] = (ll[0][l - j - 1] * 26 + s1[j] - 'a') % mod[0];
            ll[1][l - j] = (ll[1][l - j - 1] * 26 + s1[j] - 'a') % mod[1];
        }
        for (int j = r + 1; j < le; j++) {
            rr[0][j - r] = (rr[0][j - r - 1] * 26 + s1[j] - 'a') % mod[0];
            rr[1][j - r] = (rr[1][j - r - 1] * 26 + s1[j] - 'a') % mod[1];
        }
        for (int i = 1; i <= n; i++) {
            if (u[0][i] == U[0] && u[1][i] == U[1] && lenl[i] <= l &&
                v[0][i] == V[0] && v[1][i] == V[1] && lenr[i] <= le - r - 1) {
                if (ll[0][lenl[i]] == L[0][i] && ll[1][lenl[i]] == L[1][i] &&
                    rr[0][lenr[i]] == R[0][i] && rr[1][lenr[i]] == R[1][i])
                    ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
