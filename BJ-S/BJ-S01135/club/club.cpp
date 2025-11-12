#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[N];
int ans = 0;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	//freopen("club.in", "r", stdin);
    //freopen("club.out", "w", stdout);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t ;
    while(t--) {
		int x;
		cin >> n ;
		for(int i = 1; i <= n; i++) cin >> a[i] >> x >> x ;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n / 2; i++) ans += a[i];
        cout << ans << endl;
    }
    return 0;
}
// Everything is gone......I only have 10pts......
