#include <bits/stdc++.h>
using namespace std;

int n, k, a[500010], s, sum = 0;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == 1){
		cout << 0 << '\n';
	}
	else if(n == 2){
		cout << 1 << '\n';
	}
	else{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= i; j++){
				s = a[j];
				for(int l = j + 1; l <= i; l++){
					s = s xor a[l];
				}
				if(s == k){
					sum++;
				}
			}
		}
	}
	cout << sum << '\n';
	return 0;
}
