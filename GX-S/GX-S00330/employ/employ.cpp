#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

const int N = 1e5 + 10;
int n, m;
int s[N] = {};
int c[N] = {};
bool vis[N] = {};
int d[N] = {};
ll ans = 0;
void dfs(int k, int res) {
    if (k == n) {
        if (res >= m) {
            ans ++;
        }
            cout << res << '\n';
    }
    else {
        for (int i=0;i<n;i++) {
            if (vis[i] == 0 && c[i] > d[k]) {
                vis[i] = 1;
                if (s[i] == 0)
                    dfs(k+1, res+1);
                else {
                    dfs(k+1, res);
                }
                vis[i] = 0;
            }
            else if (vis[i] == 0) {
                vis[i] = 1;
                    dfs(k+1, res);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        cin >> s[i];
        if (s[i]&&i>0) d[i] = d[i-1];
        if (s[i]==0&&i>0) d[i] = d[i-1]+1;
    }

    for (int i=0;i<n;i++) {
        cin >> c[i];
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}
