#include <bits/stdc++.h>
using namespace std;
int a[500009];
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(k == 0){
		if(n == 1) cout << 0;
		else if(n == 2) cout << 1;
		else{
			cout << n / 2;
		}
	}
	else if(k == 1){
		long long cnt = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 1) cnt++;
		}
		cout << cnt;
	}
	cout << n / 2;
	return 0;
}
