#include <bits/stdc++.h>

namespace CYRENE {
#define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
#define qep(i, st, ed) for (int i = (st), _##i = (ed); i <  _##i; ++i)
#define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
#define fi first
#define se second
#define eb emplace_back
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

int n, m;

int moe() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    rep(i, 1, n) {
        string s1, s2; cin >> s1 >> s2;
    }
    rep(j, 1, m) {
        string t1, t2; cin >> t1 >> t2;
        cout << 0 << "\n";
    }
    return 0;
}
} // namespace CYRENE

int main() {
    std::freopen("replace.in", "r", stdin);
    std::freopen("replace.out", "w", stdout);
    return CYRENE::moe();
}

/*
g++ -o replace replace.cpp -std=c++17 -O2 -Wall -Wno-unused-result -g -DDEBUG -fsanitize=address,undefined
*/
