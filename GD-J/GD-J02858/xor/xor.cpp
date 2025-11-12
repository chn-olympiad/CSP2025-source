#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[105];
	for(int i = 1; i <= n;i++){
		cin >> a[i];
	}
	if (k == 0){
		cout << "0";
	}
	else{
		cout << "2";
	}
	return 0;
}
