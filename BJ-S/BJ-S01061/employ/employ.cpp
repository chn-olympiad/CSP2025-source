#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 500 + 10;

int n, m, cnt, box[N], c[N];

string s;

bool luyong[N], vis[N];

void dfs(int x){
    if (x > n){
        memset(luyong, 0, sizeof luyong);
        int can = 0;
        for (int i = 1; i <= n; i++){
            bool f = true;
            for (int j = box[i] - c[box[i]] + 1; j <= box[i]; j++)
                if (luyong[j]) { f = 0; break; }
            if (!f && s[box[i]] == '1') { can++; luyong[box[i]] = 1; }
        }
        if (can >= m) cnt++;
        return ;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i]){
            vis[i] = 1;
            box[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) cin >> c[i];
    dfs(1);
    cout << cnt << '\n';
    return 0;
}