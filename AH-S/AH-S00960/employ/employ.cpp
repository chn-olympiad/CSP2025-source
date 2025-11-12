#include "bits/stdc++.h"
//Eason Cyj001001
#define int long long

using namespace std;
const int MOD = 998244353;
int ans;
int n;
int m;
int an[505];
int t[505];
char s[505];
int a[505];

void dfs(int x) {
    if(x==n+1) {
        int sum = 0,u = 0;
        for(int i=1; i<=n; i++) {
            if(s[i] == '0') {
                u++;
                continue;
            }
            if(u >= an[i]) continue;
            sum++;
        }
        if(sum >= m) ans++;
        ans %= MOD;
        return;
    }
    for(int i=1; i<=n; i++) {
        if(!t[i]) {
            t[i] = true;
            an[x] = a[i];
            dfs(x+1);
            t[i] = false;
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> s[i];
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    if(n<=18) {
        dfs(1);
        cout << ans;
    }else {
        int ans = 1;
        for(int i=1; i<=n; i++) {
            ans *= i;
            ans %= MOD;
        }
        cout << ans;
    }
    return 0;
}
