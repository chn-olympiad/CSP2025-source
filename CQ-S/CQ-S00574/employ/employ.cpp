#include <bits/stdc++.h>
#define mod 998244353ll
using namespace std;
int n, m;
string a;
int sz[510];
bool vis[510];
set<vector<int> > ans;
void dfs(int p, int x, int rs, vector<int> &ls){
    if(n - rs  < m) return;
    if(p > n){
        if(rs >= m){
            ans.insert(ls);
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = 1;
            ls.push_back(i);
            dfs(p+1, x+1, rs, ls);
            if(x < sz[i] && a[p] == '1'){
                dfs(p+1, x, rs+1, ls);
            }
            ls.pop_back();
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    cin >> a;
    a = " " + a;
    for(int i=1;i<=n;i++){
        cin >> sz[i];
    }
    vector<int> bl;
    dfs(1, 0, 0, bl);
    printf("%lld", ans.size());
    return 0;
}