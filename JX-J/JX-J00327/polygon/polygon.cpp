#include <bits/stdc++.h>
using namespace std;
int c[5005];
int ans = 0;
int n;
unordered_map<int,bool> vis;
unordered_map<string,bool> vis2;
void dfs(int i,int step,int maxs,string s) {
    if (i == 0) {
        sort(s.begin(),s.end());
        if (step > 2 * maxs && !vis2[s]) ++ans,vis2[s] = 1;
        return;
    }
    for (int j=1;j<=n;++j) {
        if (!vis[j]) {
            vis[j] = 1;
            dfs(i - 1,step + c[j],max(maxs,c[j]),s + to_string(j));
            vis[j] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> c[i];
    for (int i=1;i<=n;++i) vis.clear(),dfs(i,0,0,"");
    cout << ans;
    return 0;
}
