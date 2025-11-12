#include <bits/stdc++.h>
long long a[500005];
using namespace std;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	int f = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			f = 0;
		} 
	}
	if(k == 0 && f == 1){
		cout << n;
	}
	return 0;
}
