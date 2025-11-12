#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 5e3 + 5, mod = 998244353;
int a[maxn];
long long ans = 0;

void dfs(int idx, int sum, int maxx){
    if(idx > n){
        if(sum > maxx * 2)  ans = (ans + 1) % mod;
        return ;
    }

    dfs(idx + 1, sum + a[idx], max(a[idx], maxx));
    dfs(idx + 1, sum, maxx);
    return ;
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1;i <= n;++i)  cin>>a[i];
    dfs(1, 0, 0);
    cout<<ans<<'\n';
    return 0;
}
