#include <bits/stdc++.h>
#define N 555
#define mod 998244353
#define int long long
using namespace std;
vector<bool> d;
vector<int> n1;
int a[N];
int dfs(int n, int m, int k, int nn, int cc, int state = 0){
    nn += n1[k] - (k ? n1[k - 1]: -1) - 1;
    if(k == n1.size()) return cc >= m;
    if(cc + n1.size() - k < m) return 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(state >> i & 1) continue;
        cnt += dfs(n,
                   m,
                   k + 1,
                   nn + (a[i] <= nn),
                   cc + (a[i] > nn),
                   state ^ 1 << i);
        cnt %= mod;
    }
    return cnt;

}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        d.emplace_back(c == '1');
        if(c == '1') n1.emplace_back(i);
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << dfs(n, m, 0, 0, 0, 0) << endl;
    return 0;
}
