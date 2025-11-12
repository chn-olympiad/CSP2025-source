#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[500010],sum1;

bool flag;

int main(){
	int n,k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i] != 1) flag = 1;
		if(a[i] == 1) sum1++;
	}
	if(k == 0 && !flag){
		cout << 0;
		return 0;
	}
	if(k <= 1){
		if(k == 0) cout << n - sum1; 
		else cout << sum1;
	}
	return 0;
}
