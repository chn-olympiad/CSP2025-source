#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<queue>
#define int long long
#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 100005

using namespace std;

int n, sum, a[maxn][5];

vector<int> g[5];

void work() {
    sum = 0;
    cin >> n;
    g[1].clear(); g[2].clear(); g[3].clear();
    for(int i = 1; i <= n; i++) {
        int mx = -1, k = 0;
        for(int j = 1; j <= 3; j++) {
            cin >> a[i][j];
            if(a[i][j] > mx) mx = a[i][j], k = j;
        }
        sum += mx;
        sort(a[i] + 1, a[i] + 4);
        int mx2 = a[i][2];
        g[k].push_back(mx - mx2);
    }
    for(int i = 1; i <= 3; i++) {
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
        for(int j = n / 2; j < g[i].size(); j++) sum -= g[i][j];
    }
    cout << sum << '\n';
}

signed main() {
    fopen("club");
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) work();
}