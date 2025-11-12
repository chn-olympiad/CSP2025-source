#include<bits/stdc++.h>
using namespace std;
int n, a[5005], ans = 0;
int main() {
    freopen("polygon4.in","r",stdin);
    freopen("polygon4.ans","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < (1 << n); i++) {
        int sum = 0, maxn = 0;
        for(int j = 0; j < n; j++) {
            if(((1 << j) & i) == 0) {
                sum += a[j + 1];
                maxn = max(a[j + 1], maxn);
            }
        }
        if(sum > maxn * 2) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
