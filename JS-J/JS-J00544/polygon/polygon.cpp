#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3;
const int Mod = 998244353;
int a[N + 5],ans,n;
void dfs(int k,int dep,int sum,int b) {
    if(dep == k) {
        if(sum > a[b] * 2) ans ++;
        ans %= Mod;
        return ;
    }
    for(int i = b + 1 ; i <= n ; i ++)
        dfs(k,dep + 1,sum + a[i],i);
}
signed main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    if(a[n] == 1) {
        int l,ad;
        ans = l = ad = 0;
        for(int i = 1 ; i <= n ; i ++) {
            ad ++,l += ad;
            ans += l;
            ans %= Mod;
        }
        cout << ans << endl;
        return 0;
    }
    for(int k = 3 ; k <= n ; k ++)
        for(int i = 1 ; i <= n - k + 1 ; i ++)
            dfs(k,1,a[i],i);
    cout << ans << endl;
    return 0;
}
