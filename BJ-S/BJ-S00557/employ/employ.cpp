#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

const int Maxn = 505;
int frac[Maxn];

int ans, n, m;
bool vis[15];
int p[15], c[15];
string s;

void dfs(int step){
    if(step == n + 1){
        int suc = 0, fal = 0;
        for(int i = 1; i <= n; i ++){
            if(fal >= c[p[i]]){
                fal ++;
                continue;
            }
            if(s[i - 1] == '1') suc ++;
            else fal ++;
        }
        if(suc >= m) ans = (ans + 1) % mod;
    }

    for(int i = 1; i <= n; i ++){
        if(vis[i]) continue;
        vis[i] = 1;
        p[step] = i;
        dfs(step + 1);
        vis[i] = 0;
    }
}

bool flag;
int cnt = 0;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i ++) cin >> c[i];

    if(n <= 10){
        dfs(1);
        cout << ans;
        return 0;
    }

    return 0;
}
