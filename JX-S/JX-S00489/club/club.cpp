#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int N = 1e5+10;
int xqw(int x) {
	
}
int t, n, ans = 0;
int a1[N], a2[N], a3[N];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);	
    IOS;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 2) {
			cin >> a1[0] >> a2[0] >> a3[0]>> a1[1] >> a2[1] >> a3[1];
			int qqq[5];
			qqq[0] = a1[0] + a2[1];
			qqq[1] = a1[0] + a3[1];
			qqq[2] = a2[0] + a1[1];
			qqq[3] = a2[0] + a3[1];
			qqq[4] = a3[0] + a1[1];s
			qqq[5] = a3[0] + a2[1];
			sort(qqq, qqq + 6);
			cout << qqq[5] << "\n";
			return 0;
		}
		else {
        for(int i = 1; i <= n; i++) {
            cin >> a1[i] >> a2[i] >> a3[i];
        }
        if(a2[0] == 0 && a3[0] == 0) {
			sort(a1 + 1, a1 + n + 1);
			for(int i = n; i > n / 2; i--)
				ans += a1[i];
		}
		else if(a3[0] == 0) {
			for(int i = 1; i <= n; i++) {
				
			}
		}
		cout << ans << "\n";
		ans = 0;
		}
	}
    return 0;
}
