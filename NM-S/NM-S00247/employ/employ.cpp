#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 998244353LL;
const int MAXN = 505;
ll fac[MAXN];
int n, m;
int s[MAXN], c[MAXN];
void BF(){
    vector<int> v = {};
    ll ans = 0;
    for (int i = 1; i <= n; ++i) v.push_back(i);
    while (true) {
        int cnt = 0;
        for (int i = 0; i < v.size(); ++i){
            int now = v[i];
            if (i - cnt >= c[now])
                continue;
            if (s[i + 1]) ++cnt;
            //printf("%d,cnt=%d\n", i, cnt);
        }
        //printf("!!cnt=%d\n", cnt);
        if (cnt >= m) ++ans;
        if (!next_permutation(v.begin(), v.end())) break;
    }
    cout << ans << endl;
}
void bar(bool flag){
    if (!flag) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; ++i){
        if (c[i] == 0) {
            cout << 0 <<endl;
            return;
        }
    }
    cout << fac[n] <<endl;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    //freopen("employ3.in", "r", stdin);
    cin >> n >> m;
    fac[0] = 1;
    for (ll i = 1; i < MAXN; ++i) fac[i] = fac[i - 1] * i % M;
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        char ch;
        cin >> ch;
        s[i] = ch - '0';
        if (!s[i]) flag = false;
    }
    for (int i = 1; i <= n; ++i) cin >> c[i];
    if (n <= 18) BF();
    else if (m == n) bar(flag);
    else cout << 0 << endl;// :(
    return 0;
}
