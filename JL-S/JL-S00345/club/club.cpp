#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define per(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define PII pair<int, int>

const int N = 100010;
int tc;
int n, a[N][3];
vector<pair<int, PII>> e[3];

void solve() {
    scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        int x = max({a[i][0], a[i][1], a[i][2]});
        int p = -1;
        rep(j, 0, 2)
            if(x == a[i][j]) {
                p = j;
                break;
            }
        int ma = 0;
        rep(j, 0, 2)
            if(j != p) ma = max(ma, a[i][j]);
        e[p].push_back({x - ma, {x, i}});
    }
    rep(i, 0, 2)
        sort(e[i].begin(), e[i].end()),
        reverse(e[i].begin(), e[i].end());
    if(e[0].size() > n / 2) {
        int sz = e[0].size();
        rep(i, n / 2, sz - 1) {
            int j = e[0][i].second.second;
            int x = max(a[j][1], a[j][2]);
            rep(k, 0, 2)
                if(x == a[j][k] && k != 0) {
                    e[k].push_back({0, {x, 0}});
                    break;
                }
        }
        rep(i, n / 2, sz - 1)
            e[0].pop_back();
    } else if(e[1].size() > n / 2) {
        int sz = e[1].size();
        rep(i, n / 2, sz - 1) {
            int j = e[1][i].second.second;
            int x = max(a[j][0], a[j][2]);
            rep(k, 0, 2)
                if(x == a[j][k] && k != 1) {
                    e[k].push_back({0, {x, 0}});
                    break;
                }
        }
        rep(i, n / 2, sz - 1)
            e[1].pop_back();
    } else if(e[2].size() > n / 2) {
        int sz = e[2].size();
        rep(i, n / 2, sz - 1) {
            int j = e[2][i].second.second;
            int x = max(a[j][0], a[j][1]);
            rep(k, 0, 2)
                if(x == a[j][k] && k != 2) {
                    e[k].push_back({0, {x, 0}});
                    break;
                }
        }
        rep(i, n / 2, sz - 1)
            e[2].pop_back();
    }
    int ans = 0;
    rep(i, 0, 2)
        for(auto [x, y] : e[i])
            ans += y.first;
    printf("%d\n", ans);
}

void clear() {
    rep(i, 0, 2)
        e[i].clear();
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &tc);
    while(tc--)
        solve(), clear();
}
