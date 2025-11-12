#include <bits/stdc++.h>
using namespace std;
int cnt, sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, sum;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		while(t){
			sum += t % 2;
			t /= 2;
		}
	}
	cout << (sum * (sum - 1)) / 3;
	return 0;
} 
