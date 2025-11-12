#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5e3 + 10, M = 998244353;
int a[N], s[N], ans;
void dfs(int step, int sum, int side, int mx);
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        s[i] = s[i - 1] + a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i=n; i>=3; i--){
        if(s[i - 1] <= a[i]) break;
        dfs(1, 0, i - 1, a[i]);
    }
    cout<<ans;
    return 0;
}
void dfs(int step, int sum, int side, int mx){
    if(step == side + 1){
        if(sum > mx){
            ans++;
            ans %= M;
        }
        return;
    }
    dfs(step + 1, sum, side, mx);
    dfs(step + 1, sum + a[step], side, mx);
}
