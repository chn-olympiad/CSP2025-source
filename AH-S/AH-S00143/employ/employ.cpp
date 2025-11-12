//exam: employ.cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long
//#define OI
using namespace std;
const int MAXN = 505, P = 998244353;
int a[MAXN], id[MAXN];
string s;
int n, m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifndef OI
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    #endif

    cin >> n >> m >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = i;
    }

    sort(a + 1, a + 1 + n);

    int res = 0;
    do{
        int ans = 0;
        for(int i = 1, cnt = 0; i <= n; i++) {
            if(s[i] == '1' && a[id[i]] > cnt) {
                ans++;
                if(ans == m) {
                    break;
                }
            } else {
                cnt++;
            }
        }
        if(ans >= m) {
            res = (res + 1) % P;
        }
    } while(next_permutation(id + 1, id + 1 + n));
    cout << res;
    return 0;
}
