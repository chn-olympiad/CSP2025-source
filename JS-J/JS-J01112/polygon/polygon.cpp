#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5050,mod = 998244353;
int n,a[N];
ll K[N],p[N],ans;
int dfs(int x,int s,int f,int d) {
    if(s > f) return 0;
    if(d <= 2) {
        int l = 1,r = x - 1,mid = 0,res = 0;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(a[mid] + s <= f) l = mid + 1;
            else r = mid - 1;
        }
        d ++;
        for(int i = mid;i;i --) {
            res += dfs(i,s + a[i],f,d);
            res %= mod;
        }
        return res;
    }
    int res = 1;
    int l = 1,r = x - 1,mid = 0;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(a[mid] + s <= f) l = mid + 1;
        else r = mid - 1;
    }
    for(int i = mid;i;i --) {
        res += dfs(i,s + a[i],f,d);
        res %= mod;
    }
    return res;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1,a + 1 + n);
    if(n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    if(n == 3) {
        if(a[1] + a[2] > a[3]) cout << 1 << '\n';
        else cout << 0 << '\n';
        return 0;
    }
    if(a[n] == 1) {
        p[n] = n,K[1] = 1;
        for(int i = n - 1,j = 2;i;i --,j ++) {
            p[i] = p[i + 1] * i;
            K[j] = K[j - 1] * j;
            if(j > 2) {
                ans += p[i] / K[j];
                ans %= mod;
            }
            p[i + 2] %= mod;
            K[j - 2] %= mod;
        }
        cout << ans << '\n';
        return 0;
    }
    p[n] = n,K[1] = 1;
    for(int i = n - 1,j = 2;i;i --,j ++) {
        p[i] = p[i + 1] * i;
        K[j] = K[j - 1] * j;
        if(j > 2) {
            ans += p[i] / K[j];
            ans %= mod;
        }
        p[i + 2] %= mod;
        K[j - 2] %= mod;
    }
    for(int i = n;i >= 3;i --) ans -= dfs(i,0,a[i],1);
    cout << ans << '\n';
    return 0;
}