#include<bits/stdc++.h>
using namespace std;
int n , k , a , b[500005] , cnt = 0;
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a;
		b[i] = b[i - 1] ^ a;
	}
	if(n == 2)cnt = 2;
	else{
		for(int i = 1; i <= n; i ++){
			for(int j = i; j <= n; j ++){
				if(b[j] ^ b[i] == k){
					cnt ++ , i = j + 1;
					break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}