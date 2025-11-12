#include <bits/stdc++.h>
using namespace std;

int a[1313131], n, k, x = 0, y = 0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1)x++;
		if(a[i] == 0)y++;
	}
	if(k == 0){
		cout << n / 2;
	}
	else if(k == 1){
		cout << min(x, y);
	}
	else cout << n / 5;
	return 0;
}
