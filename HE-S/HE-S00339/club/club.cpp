#include<bits/stdc++.h>
using namespace std;
const int N = 800010;
int c1[N], c2[N], c3[N];
int f[10], cnt;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		for(int i = 0; i < n; i ++) cin >> c1[i] >> c2[i] >> c3[i];
		f[0] = c1[0] + c2[1];
		f[1] = c1[0] + c3[1];
		f[2] = c2[0] + c1[1];
		f[3] = c2[0] + c3[1];
		f[4] = c3[0] + c1[1];
		f[5] = c3[0] + c2[1];
		int ans = 0;
		for(int i = 0; i < 6; i ++) ans = max(ans, f[i]);
		cout << ans << endl;
		
	}
	return 0;
}
