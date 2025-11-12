#include <bits/stdc++.h>
#define N 5050
#define mod 998244353
using namespace std;
typedef long long ll;
int n;
int a[N];
int pre[N];
int ans;
int main() {
    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int l, r, sum, mx;
    for(int i = 3; i <= n; i++) {
        l = 1;
        r = i;
        mx = *max_element(a + 1, a + r + 1);
        while(r <= n) {
            sum = pre[r] - pre[l - 1];
            if(mx * 2 < sum) {
                ans = (ans + 1) % mod;
            }
            l++;
            r++;
            mx = max(mx, a[r]);
        }
    }
    cout << ans;
}
