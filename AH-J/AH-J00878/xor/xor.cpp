#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, a[100001] , k , cnt = 0;
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(LL i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] == k || a[i] + a[i - 1] == k || abs(a[i] - a[i - 1])) cnt++;
	} 
	cout << cnt;
	return 0;
}
