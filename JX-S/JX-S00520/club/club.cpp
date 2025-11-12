#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x) {
    x = 0; char ch = getchar(); bool ff = 0;
    while(ch < '0' || ch > '9') ff |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
    x = ff ? -x : x;
}
template <typename T, typename ...T1> void read(T &x, T1 &...x1) {
    read(x); read(x1...);
}
#define int long long
const int maxn = 1e5 + 5;
int n, a[maxn][4], sum[4];
priority_queue <int, vector<int>, greater<int>> det[4];
void init() {
    for(int i = 1; i <= 3; i ++) {
        sum[i] = 0;
        while(!det[i].empty()) det[i].pop();
    }
}
void Solve() {
    read(n);
    init();
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int maxx = 0, mid = 0, id = 0;
        for(int j = 1; j <= 3; j ++) {
            read(a[i][j]);
            if(a[i][j] > maxx) {
                mid = maxx;
                maxx = a[i][j];
                id = j;
            }
            else mid = max(mid, a[i][j]);
        }
        ans += maxx;
        sum[id] ++;
        det[id].push(maxx - mid);
    }
    //cout << 11111111 << endl;
    for(int i = 1; i <= 3; i ++) {
        while(sum[i] > n / 2) {
            ans -= det[i].top();
            det[i].pop();
            sum[i] --;
        }
    }
    printf("%lld\n", ans);
}
#undef int
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    read(T);
    while(T --) {
        Solve();
    }
    return 0;
}
