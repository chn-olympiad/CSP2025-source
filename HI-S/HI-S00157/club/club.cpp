#include<bits/stdc++.h>
using namespace std;
bool cmp (int x, int y) {
	return x > y; 
} 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, a1[100005], a2[100005], a3[100005];
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i = 1; i <= n; i++) {
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1 + 1, a1 + 1 + n, cmp);
		int ans = 0;
		for (int i = 1; i <= n / 2; i++) {
			ans += a1[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
