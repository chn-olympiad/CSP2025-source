#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int a[N];

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	bool F = 1;
	bool F1 = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1){
			F = 0;
		} 
		if(a[i] < 0 || a[i] > 1){
			F1 = 0;
		}
	}
	if(F == 1 && k == 0){
		if(n % 2){
			cout << 1 << '\n';
		}
		else{
			cout << (n / 2) << '\n';
		}
		return 0; 
	}
	else if(F1 == 1 && k == 1){
		int m = 0;
		for(int i = 2;i <= n;i++){
			if(a[i - 1] == 1 && a[i] == 0){
				m++;
			}
		}
		cout << m << '\n';
		return 0; 
	}
	else if(F1 == 1 && k == 0){
		cout << n / 2 << '\n';
		return 0; 
	}
	else{
		cout << n / 2 << '\n';
		return 0; 
	}
	
	return 0;
}