//exam: club.cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
//#define OI
using namespace std;
struct node {
    int a, b, c, maxn;
    int gmax() {
        return max({a, b, c});
    }
    bool operator < (const node &nxt) const {
        return maxn > nxt.maxn;
    }
};
const int MAXN = 1e5+5;
int modify(int res, const vector<node> &v);
node a[MAXN];
int t, n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifndef OI
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    #endif

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1, x, y, z; i <= n; i++) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            a[i].maxn = a[i].gmax();
        }

        int res = 0;
        vector<node> a1, a2, a3;

        for(int i = 1; i <= n; i++) {
            int maxn = a[i].maxn;
            if(a[i].a == maxn) {
                a1.push_back(a[i]);
            } else if(a[i].b == maxn) {
                a2.push_back(a[i]);
            } else {
                a3.push_back(a[i]);
            }
            res += maxn;
        }

        if(a1.size() > (n >> 1)) {
            cout << modify(res, a1) << endl;
        } else if(a2.size() > (n >> 1)) {
            cout << modify(res, a2) << endl;
        } else if(a3.size() > (n >> 1)) {
            cout << modify(res, a3) << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}
int modify(int res, const vector<node> &v) {
    vector<int> tmp;
    for(auto x : v) {
        int maxn = x.maxn, _maxn;
        if(maxn == x.a) {
            _maxn = max(x.b, x.c);
        } else if(maxn == x.b) {
            _maxn = max(x.a, x.c);
        } else {
            _maxn = max(x.a, x.b);
        }
        tmp.push_back(maxn - _maxn);
    }

    sort(tmp.begin(), tmp.end());

    int len = v.size();
    for(auto x : tmp) {
        res -= x;
        len--;
        if(len == (n >> 1)) {
            break;
        }
    }

    return res;
}
