#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n == 1){
		if (a[1] == k){
			cout << 1;
			return 0;
		} 
		else{
			cout << 0;
			return 0;
		}
	}
	else if (n == 2){
		if (a[1] == k && a[2] == k){
			cout << 2;
			return 0;
		}
		else if (a[1] ^ a[2] == k){
			cout << 1;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	else{
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (a[i] == k)cnt++;
		}
		cout << cnt;
	}
	return 0;
}
