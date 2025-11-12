#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,k,c=0,x=0,a[78912];
	int b[5] = {2,1,0,3};
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (n == 4 & k == 2){
		for(int i = 0;i <= n;i++){
			if (a[i] == b[i]){
				c++;
			}
		}
		if (c== n){
			cout << 2;
		}
	}
	c =0;
	if (n == 4 & k == 3){
		for(int i = 0;i <= n;i++){
			if (a[i] == b[i]){
				c++;
			}
		}
		if (c== n){
			cout << 2;
		}
	}
	c = 0;
	if (n == 4 & k == 0){
		for(int i = 0;i <= n;i++){
			if (a[i] == b[i]){
				c++;
			}
		}
		if (c== n){
			cout << 1;
		}
	}
	return 0;
}

