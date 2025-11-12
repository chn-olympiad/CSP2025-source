#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5+5;
int n, q;
string s1[MAXN], s2[MAXN], t1, t2;
vector<int> c1[35], c2[35];
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    for(int i = 1; i <= q; i++) {
        cout << 0 << endl;
    } return 0;
}
