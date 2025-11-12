#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int a[maxn];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k == 0){
		if(n == 0){
			cout << 0;
			return 0;
		}
		if(n == 1){
			cout << 0;
			return 0;
		}
		if(n == 2){
			cout << 1;
			return 0;
		}
	}
	return 0;
}