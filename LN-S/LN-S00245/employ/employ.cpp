#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 505;
int n, m, ans;
string s;
int c[N], vis[N];

void dfs(int idx, int x){
    if (idx > n){
        if (x == m){
            ans ++;
            ans %= 998244353;
        }
        return;
    }
    for (int i = 1; i <= n; i ++){
        if (vis[i]) continue;
        //cout << idx << ' ' <<  i << endl;
        vis[i] = 1;
        //cout << c[i] << ' ' << x << "\n\n";
        if (s[idx] == '1' && c[i] > (idx-1-x)){
            //cout << "yes"<< endl;
            dfs(idx+1, x+1);
        }
        else{
            dfs(idx+1, x);
        }
        vis[i] = 0;
    }
}

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    s = '0' + s;
    //cout << s << endl;
    for (int i = 1; i <= n; i ++){
        cin >> c[i];
    }
    int cnt = 0;
    for (char i : s){
        if (i == '1') cnt ++;
    }
    if (cnt < m){
        cout << 0 << endl;
        return 0;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
