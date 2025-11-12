#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n, q, pw[5000005], a[200005], b[200005], len[200005], x[5000005], y[5000005];
string s, t;
int check1(int i, int j){
    return x[j] - x[i - 1] * pw[j - i + 1];
}
int check2(int i, int j){
    return y[j] - y[i - 1] * pw[j - i + 1];
}
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    pw[0] = 1;
    for (int i = 1; i <= 5000000; i++) pw[i] = pw[i - 1] * 131;
    for (int i = 1; i <= n; i++){
        cin >> s >> t;
        len[i] = s.length();
        for (int j = 0; j < s.length(); j++) a[i] = a[i] * 131 + s[j] - 'a';
        for (int j = 0; j < t.length(); j++) b[i] = b[i] * 131 + t[j] - 'a';
    }
    for (int cnt = 1; cnt <= q; cnt++){
        cin >> s >> t;
        int l = s.length();
        s = " " + s, t = " " + t;
        int ans = 0;
        for (int j = 1; j <= l; j++) x[j] = x[j - 1] * 131 + s[j] - 'a';
        for (int j = 1; j <= l; j++) y[j] = y[j - 1] * 131 + t[j] - 'a';
        for (int i = 1; i <= l; i++){
            for (int j = i; j <= l; j++){
                for (int k = 1; k <= n; k++){
                    if (len[k] != j - i + 1) continue;
                    if (a[k] == check1(i, j) && b[k] == check2(i, j)){
                        if ((check1(1, i - 1) == check2(1, i - 1) || i == 1) && (check1(j + 1, l) == check2(j + 1, l) || j == l)) ans++;//, cout << i << " " << j << " " << k << "\n";
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
