#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (k==0){
        cout << n;
        return 0;
    }
    int mx = 0, t;
    for (int i =1;i<=n;i++) {
        int ll=a[1];
        for(int l=2;l<=i;l++) {
            ll^=a[l];
        }
        t=ll;
        int rr=a[i];
        for (int r=i+1;r <=n;r++) {
            rr^=a[r];
        }
        if (ll==rr) {
            mx=max(mx,ll);
        }
    }
    cout << mx;
    return 0;
}