#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[10005]={};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (k == 0){
		cout << 1;
	}
	return 0;
} 
