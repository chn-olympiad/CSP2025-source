#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 2e5 + 6;
const ll base = 37, mod = 1e9 + 9;
string s1[N], s2[N], t1[N], t2[N];
int n, q, sfs[N], sft[N], Ls[N], Rs[N], Lt[N], Rt[N];
bool dms[N], dmt[N];
bool check(string s[], int n) {
    for (int i = 0; i < n; i++) {
        int cb = 0;
        for (char c : s[i])
            if (c == 'b')cb++;
            else if (c != 'a')return false;
        if (cb != 1)return false;
    }
    return true;
}
void prepro() {
    for (int i = 0; i < n; i++) {
        int l = 0, r = s1[i].length() - 1;
        while (l < r && s1[i][l] == s2[i][l])l++;
        while (l < r && s1[i][r] == s2[i][r])r--;
        if (l == s1[i].length())dms[i] = true;
//        if (s1[i][l] == 'b')sfs[i] = r - l;
        Ls[i] = l, Rs[i] = r;
//        cout<<l<<' '<<r<<'\n';
    }
    for (int i = 0; i < q; i++) {
        int l = 0, r = t1[i].length() - 1;
        while (l < r && t1[i][l] == t2[i][l])l++;
        while (l < r && t1[i][r] == t2[i][r])r--;
        if (l == t1[i].length())dmt[i] = true;
//        if (t1[i][l] == 'b')sft[i] = r - l;
        Lt[i] = l, Rt[i] = r;
//        cout<<l<<' '<<r<<'\n';
    }
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++)cin >> s1[i] >> s2[i];
    for (int i = 0; i < q; i++)cin >> t1[i] >> t2[i];
    prepro();
//    if (check(s1, n) && check(s2, n) && check(t1, q) && check(t2, q)) {
//        solveB();
//        continue;
//    }
    for (int i = 0; i < q; i++) {
        int l = Lt[i], r = Rt[i], ans = 0;
        for (int j = 0; j < n; j++) {
            if (Ls[j] <= l && s1[j].length() - Rs[j] <= t1[i].length() - r && Rs[j] - Ls[j] == Rt[i] - Lt[i]) {
//                cout<<"In\n";
                int l1 = l - Ls[j], ok = 1;
                for (int k = 0; s1[j][k]; k++, l1++) {
//                    cout << i << ' ' << j << ' ' << k << '\n';
                    if (s1[j][k] != t1[i][l1] || s2[j][k] != t2[i][l1]) {
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
            }
        }
        cout << ans << '\n';
    }
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
