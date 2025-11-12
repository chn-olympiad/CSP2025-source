#include <bits/stdc++.h>
using namespace std;

int n, k, cnt0, cnt1;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if (x == 0){
			cnt0++;
		}
		else{
			cnt1++;
		}
	}
	if (k == 0){
		cout << cnt0 << "\n";
	}
	else{
		cout << cnt1 << "\n";
	}
	
	return 0;
}
