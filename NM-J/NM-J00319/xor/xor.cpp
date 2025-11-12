#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[n];
int main(){
	freopen("xor.in","r","strain");
	freopen("xor.out","w","stdout");
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n = 1){
		cout << 1;
	}
	return 0;
}
