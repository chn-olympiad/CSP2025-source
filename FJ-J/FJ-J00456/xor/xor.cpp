#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
bool st[N];
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	bool f = true;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		if(a[i] != 1) f = false;
	}
	if(f && m == 0){
		cout << n / 2 << '\n';
		return 0;
	}
	if(n <= 2){
		int ans1 = 0 , ans2 = 0;
		if(a[1] == m) ans1 ++;
		if(a[2] == m) ans1 ++;
		int x = a[1] ^ a[2];
		if(x == m) ans2 ++;
		cout << max(ans1 , ans2) << '\n';
		return 0;
	}
	if(m == 1){
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(a[i] == 1){
				cnt ++;
			}
		}
		cout << cnt << '\n';
		return 0;
	}
	if(m == 0){
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(a[i] == 0){
				ans ++;
				st[i] = 1;
			}
		}
		for(int i = 1 ; i + 1 <= n ; i ++){
			if(st[i]) continue;
			if(a[i] == 1 && a[i + 1] == 1){
				st[i] = st[i + 1] = 1;
				ans ++;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	memset(st , false , sizeof(st));
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(a[i] == m){
			st[i] = 1;
			ans ++;
		}
	}
	cout << ans << '\n';
	return 0;
}
