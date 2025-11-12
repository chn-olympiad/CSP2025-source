#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n , k;
int a[maxn];
int main(){
	freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	int ans = 0;
	if (k == 1){
		for (int i = 1 ; i <= n ; i ++){
			cin >> a[i];
			if (a[i] == 1) ans++;
		}
	}
	if (k == 0){
		for (int i = 1 ; i <= n ; i ++){
			cin >> a[i];
			if (a[i] == 0) ans++;
		}
	}
	cout << ans;
	return 0;
}


