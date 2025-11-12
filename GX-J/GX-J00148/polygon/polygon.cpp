#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,a[5005];
long long ans;
void dfs(int bh,int zh,int maxx,int maxxbh) {
    zh += a[bh];
    if (zh > maxx) {
        ans += (maxxbh - bh);
        return ;
    }
    for (int g = 1; bh + g < maxxbh; g++) {
        dfs(bh + g,zh,maxx,maxxbh);
    }
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j < i; j++)
            dfs(j,0,a[i],i);
    }
    cout << ans % MOD;
    return 0;
}
