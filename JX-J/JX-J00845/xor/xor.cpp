#include <bits/stdc++.h>
#define int long long
using namespace std;
struct LR{
    int l, r;
    bool operator<(const LR & o) const {
        return r < o.r;
    }
};
int n, m, a[500005], pre[500005], r, ans;
vector<int> v[(1 << 20) + 5];
vector<LR> b;
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> m;
    v[0].push_back(0);
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] ^ a[i], v[pre[i]].push_back(i);
    for (int i = 0; i <= n; i++){
        int t = pre[i] ^ m;
        auto pos = upper_bound(v[t].begin(), v[t].end(), i);
        if (pos == v[t].end()) continue;
        int p = pos - v[t].begin();
        b.push_back({i, v[t][p]});
    }
    sort(b.begin(), b.end());
    r = 0;
    for (LR i: b){
        if (i.l >= r){
            r = i.r;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
/*

  4 3
  2 1 0 3
0 2 3 3 0

0 1
1 4
2 -1
3 -1
4 -1

//freopen("xor.in", "r", stdin);
//freopen("xor.out", "w", stdout);

*/
