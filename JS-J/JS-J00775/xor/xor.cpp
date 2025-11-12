#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a[500010];

void work(){
	int ans;
	if (k == 1){
		 ans = 0;
		 for (int i = 1; i <= n; i++){
			 if (a[i] == 1) ans++;
		 }
	}else{
		ans = 1;
		for (int i = 2; i <= n; i++){
			if (a[i] == 0 && a[i - 1] != 0) ans++;
		}
		int t = (a[1] == 1);
		for (int i = 2; i <= n; i++){
			 if (a[i] == 1 && a[i - 1] == 1){
				 t++;
			 }else{
				 if(a[i] == 1 && a[i - 1] != 1){ 
					ans += t / 2;
					t = 1;
				}
			 }
		 }
	}
	cout << ans << endl;
}

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool f = true;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != 1) f = false;
	}
	if (f){
		cout << n / 2 << endl;
	}else{
		work();
	}
	return 0;
}/*
14 0
0 1 0 0 1 1 0 1 1 0 1 0 1 0
5 0
1 0 0 1 0 
*/
