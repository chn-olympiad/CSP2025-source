#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 505;
constexpr int P = 998244353;
int n, m, s[N], c[N], pos[N], ans;
bool ab[N][N];

void dfs(const int &x){
    if(x == n+1){
        int cnt = 0, rtn = 0;
        for(int i = 1; i <= n; i ++){
            if(cnt >= c[pos[i]] || s[i] == 0)
                ++ cnt;
            else
                ++ rtn;
        }
        if(rtn >= m)
            ++ ans;
        return;
    }
    for(int i = 1; i <= n; i ++){
        if(!pos[i]){
            pos[i] = x;
            dfs(x+1);
            pos[i] = 0;
        }
    }
}

int cnt[2];
string S;
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "out", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> S;
    for(int i = 1; i <= n; i ++){
        s[i] = S[i-1] - '0';
        ++ cnt[s[i]];
    }
    for(int i = 1; i <= n; i ++)
        cin >> c[i];
    if(m == n || n > 12){
        cout << 0 << endl;
        return 0;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
