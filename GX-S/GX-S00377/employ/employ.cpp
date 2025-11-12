#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int n, m, ans;
char s[N];
int c[N];
int vis[N];

void dfs(int cnt, int num) {
    if(cnt == n && num >= m) {
        ans++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(c[i] > cnt) {
                if(s[cnt+1] == '0') {
                    cnt++;
                    dfs(cnt, num);
                    cnt--;
                }
                else {
                    vis[i] = 1;
                    cnt++; num++;
                    dfs(cnt, num);
                    cnt--; num--;
                    vis[i] = 0;
                }
            }
            else {
                cnt++;
                dfs(cnt, num);
                cnt--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    dfs(0, 0);
    cout << ans << '\n';

    return 0;
}
