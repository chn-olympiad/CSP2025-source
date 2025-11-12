#include <bits/stdc++.h>
using namespace std;

int n , k , p[500010] , cnt;

int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> p[i] , p[i] ^= p[i - 1];
	int t = 0;
	for(int i = 1 ; i <= n ; i++){
		int j = t + 1;
		for( ; j <= i ; j++)
			if((p[i] ^ p[j - 1]) == k){
				t = i; cnt++;
				break;
			}
	}cout << cnt;
	return 0;
}

