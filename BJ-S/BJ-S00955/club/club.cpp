#include <bits/stdc++.h>
using namespace std;

int dp[205][4][105];
int ans = 0;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        int a[205], b[205], c[205];
        for(int j = 1; j <= n; j++) {
            cin >> a[j] >> b[j] >> c[j];
        }
        int ans1 = max(a[1]+a[2],max(a[1]+b[2],a[1]+c[2])), ans2 = max(b[1]+a[2],max(b[1]+b[2],b[1]+c[2]));
        int ans3 = max(c[1]+a[2],max(c[1]+b[2],c[1]+c[2]));
        cout <<ans1 <<endl;
        cout << max(ans1, max(ans2, ans3));
    }
    return 0;
}
