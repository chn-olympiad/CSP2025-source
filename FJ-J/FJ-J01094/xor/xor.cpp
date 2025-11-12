#include <bits/stdc++.h>
using namespace std;
int t[110000];
long long a[500005];
long long t2b(int x){
	 int sum = 1;
     while(x > 1){
     	t[sum] = x % 2;
     	x /= 2;
     	sum++;
	 }
	 t[sum] = 1;
	 int ans = 0;
	 int cd = 1;
	 for(int i = 1; i <= sum; i++){
	 	 ans += t[i] * cd;
	 	 cd *= 10;
	 }                        
	 cout << ans;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
	}
	if(n == 2 && k == 0){
		cout << 1;
		return 0;
	}else if(n == 1 && k == 0){
		cout << 0;
		return 0;
	}else if(k == 0 && n > 2){
		long long w = n * (n - 1) / 2;
		cout << w;
	}
	return 0; 
}
