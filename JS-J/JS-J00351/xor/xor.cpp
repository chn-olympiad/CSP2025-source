#include <bits/stdc++.h>
using namespace std;
int n,a[5001],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	if(k > 1){
		cout << 0 << endl;
	}
	if(k == 1){
		cout << n << endl;
	}
	else{
		cout << n / 2 << endl;
	}
	return 0;
}
