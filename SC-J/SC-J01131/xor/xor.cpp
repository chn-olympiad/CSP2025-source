#include<bits/stdc++.h>
using namespace std;
int n, a[500010], k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n%2==0){
		cout << n/2;
	}else{
		cout << n/2+1;
	}
	return 0;
}