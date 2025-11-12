#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500005], b[15];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		b[a[i]]++;
	}
	if(k == 0){
		int sum = 0;
		for(int i = 1 ; i <= n ; i++){
			if(a[i] == 0){
				sum++;
			}
			else if(a[i] == 1 && a[i-1] == 1){
				sum++;
				i++;
			}
		}
		cout << sum;
	}else if(k == 1){
		cout << b[1];
	}
	return 0;
}
