#include<bits/stdc++.h>
using namespace std;

long long n, k ;
long long a[10050];
long long q[10050];
long long ans = 0;

int main(){
	freopen("xor.in", "r",stdin);
	freopen("xor.out", "w",stdout);
	cin >> n >> k; 
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(long long i = 1; i <= n; i++){
		q[i] = (q[i - 1] ^ a[i]);
	}
	
	for(long long i = 1 ;i <= n;i++){
		for(long long j = i ;j <= n ;j++){
			if((q[j] ^ q[i - 1]) == k){
				ans ++;
				i = j + 1;
			}
		}
	}
	
	cout << ans ;
	
	return 0;
}
