#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k , ans = 0 , flag = 1;
	cin >> n >> k;
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++){
		if (a[i] != 1) flag = 0;
	}
	if (flag && k == 0){
		ans = n / 2;
	}else if(k == 0){
		for (int i = 1; i<=n; i++){
			if (a[i] == 0) ans ++;
			else{
				if (a[i + 1] == 1){
					ans ++;
					i ++;
				}
			}
		}
	}else if(k == 1){
		for (int i = 1; i<=n; i++){
			if (a[i] == 1) ans ++;
			else{
				if (a[i + 1] == 1){
					ans ++;
					i ++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
