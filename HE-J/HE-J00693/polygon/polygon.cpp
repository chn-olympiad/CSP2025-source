#include<bits/stdc++.h>
using namespace std;
long long n, one = 0, add = 0;
long long a[5500], f[100100];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1){
			one++;
		}
	}
	if(one == n){
		long long sum = 1;
		for(int i = 0; i < n; i++){
			sum *= 2;
			sum %= 998244353;
		}
//		cout << sum <<endl;
		sum = sum - n - 1;
		sum -= (n * (n - 1)) / 2;
		cout << sum % 998244353;
		return 0;
	}
	if(n == 3){
		sort(a + 1, a + 1 + n);
		if(a[1] + a[2] > a[3]){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	f[1] = a[1];
	f[2] = a[2];
	f[3] = a[1] + a[2];
	int cnt = 2;
	for(int i = 3; i < n; i++){
		cnt *= 2;
		for(int j = cnt; j < cnt * 2 - 1; j++){
			if(j == cnt){
				f[j] = a[i];
			}else{
				f[j] = f[j - cnt] + a[i];
			}
			if(f[j] > a[i + 1]){
				add = add + (cnt * 2 - 1 - j + 1);
//				for(int k = i + 2; k <= n; k++){
//					if(f[j] > a[k]){
//						add = add + (cnt * 2 - 1 - j + 1);
//					}
//				}
//				cout << "add" << add <<endl;
				add %= 998244353;
				break;
			}
		}
	}
	cout << (add % 998244353) + 1;
	return 0;
} 
