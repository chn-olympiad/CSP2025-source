#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    iota(b.begin(), b.end(), 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    do {
        int cnt = 0;
        int res = 0;
        for (int i = 1; i <= n; i++){
            if (cnt >= a[b[i]]){
                cnt ++;
                continue;
            }
            if (s[i] == '0'){
                cnt ++;
                continue;
            }
            res++;
        }
        if (res >= m){
            ans++;
        }
    }while(next_permutation(b.begin() + 1, b.begin() + n + 1));
    cout << ans << endl;
}
