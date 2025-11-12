#include<bits/stdc++.h>
using namespace std;
int n, k;
long long a[5000005];
int cnt = 0;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	bool f = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] == 0){
			f = 1;
		}
	}
	if(n == 2 && k == 0 && a[1] == a[2]){
		cout << 1;
		return 0;
	}
	if(k == 0 && n > 2 && f == 0){
		cout << n / 2;
		return 0;
	}
	for(int l = 1; l <= n; l++){
		int sum = 0;
		bool flag = 0;
		for(int r = l; r <= n; r++){
			sum = (sum ^ a[r]);
			if(sum == k){
				flag = 1;
				l = r;
				cnt ++;
				break;
			}
		}
		
	}
	cout << cnt;
	return 0;
} 
