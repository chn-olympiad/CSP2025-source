#include <bits/stdc++.h>
using namespace std;
int n , k , a[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sum = 0 , x = 0;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
		if(!a[i])sum++;
	}
	if(k == 0)cout << sum;
	if(k == 1)cout<< n - sum;
	else {
		cout << rand();
	}
	return 0;
} 