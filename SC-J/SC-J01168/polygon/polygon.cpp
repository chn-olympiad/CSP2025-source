#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5005];
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	if(n <= 3){
		sort(a + 1, a + n + 1);
		if(a[1] + a[2] > a[3]){
			cout << 1 << endl;
		} else{
			cout << 0 << endl;
		}
	} else{
		int ans = 0;
		for(int i = n - 2;i >= 0;i --){
			ans += i;
		}
		cout << ans << endl;
	}
}