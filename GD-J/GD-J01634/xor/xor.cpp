#include <cstdio>
#include <iostream>
using namespace std;
int n, k, a[500005], f;
long long ans[500005], cnt;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) f = 0;
		if(a[i] == k && i == 1) ans[1] = 1, a[i] = -1;
		if(a[i] == k) ans[i]++, a[i] = -1, cnt++;
	} 
	if(k == 0 && f){
		cout << n / 2;
		return 0;
	}
	else if(k <= 1){
		cout << cnt;
		return 0;
	}
	for(int l = 1; l <= n; l++){
		int t = a[l];
		if(a[l] == -1){
			ans[l + 1] = ans[l];
			continue;
		} 
		for(int r = l + 1; r <= n; r++){
			if(a[r] == -1){
				ans[r + 1] += ans[r];
				break;
			}
			t = t ^ a[r];
			if(t == k){
				ans[r] = ans[l] + 1;
				break;
			}
		}
	}
	cout << ans[n];
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
