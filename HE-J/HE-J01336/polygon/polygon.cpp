#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
bool f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) f = 1;
	}
	sort(a + 1,a + n + 1);
	if(n <= 2){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(a[1] + a[2] + a[3] <= a[3] * 2) cout << 0;
		else cout << 1;
		return 0;
	}
	if(f == 0){
		int ans = 0;
		for(int i = 3; i <= n; i++) ans += n - i + 1;
		cout << ans;
		return 0;
	}
	return 0;
}
