#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[6], b[6];
int mx, md;
int g1[N], g2[N], g3[N], num1, num2, num3;
int ans;
inline int max_(int aa, int bb){
	return aa > bb ? aa : bb;
}
inline void init(){
	num1 = num2 = num3 = ans = 0;
	return ;
}
inline void solve(){
	init();
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[1] >> a[2] >> a[3];
		b[1] = a[1];
		b[2] = a[2];
		b[3] = a[3];
		sort(a + 1, a + 3 + 1);
		md = a[2];
		mx = a[3];
		if(mx == b[1]) g1[++num1] = mx - md;
		else if(mx == b[2]) g2[++num2] = mx - md;
		else g3[++num3] = mx - md;
		ans += mx;
	}
	if(num1 > n / 2){
		sort(g1 + 1, g1 + num1 + 1);
		for(int i = 1; i <= num1 - n / 2; i++) ans -= g1[i];
	}else if(num2 > n / 2){
		sort(g2 + 1, g2 + num2 + 1);
		for(int i = 1; i <= num2 - n / 2; i++) ans -= g2[i];
	}else if(num3 > n / 2){
		sort(g3 + 1, g3 + num3 + 1);
		for(int i = 1; i <= num3 - n / 2; i++) ans -= g3[i];
	}
	cout << ans << '\n';
	return ;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for(int kk = 1; kk <= t; kk++) solve();
	return 0;
}
