#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool f = 1,fl = 1;
	for(int i = 1; i<=n;i++){
		cin >> a[i];
		if(a[i] != 1) f = 0;
		if(a[i] > 1) fl = 0; 
	}
	if(f){
		if(k == 0){
			if(n % 2 == 0){
				cout<<n/2;
			}else if(n % 3 == 0) cout<<n / 3;
			else cout<<0;
		}
	}else if(fl){
		int zero = 0,one = 0;
		for(int i = 1;i <= n;i++){
			if(a[i]==0) zero++;
			else one++;
		}
		if(k == 1){
			if(zero == one) cout<<n / 2;
			else cout<<n/3;
		}
	}
	return 0;
}
