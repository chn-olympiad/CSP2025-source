//exam: replace.cpp
#include <iostream>
#include <cstdio>
#define int long long
//#define OI
using namespace std;
const int MAXN = 2e5+5;
string a[MAXN], b[MAXN];
string x, y;
int n, m, res;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("replace.in", "r", stdin);
    #ifndef OI
    freopen("replace.out", "w", stdout);
    #endif

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    while(m--) {
        cin >> x >> y;
        res = 0;
        for(int i = 1; i <= n; i++) {
            int pos = x.find(a[i]);
            while(pos != -1) {
                string z = x;
                z.replace(pos, a[i].size(), b[i]);
                if(z == y) {
                    res++;
                }
                pos = x.find(a[i], pos + 1);
            }
        }
        cout << res << endl;
    }
    return 0;
}
