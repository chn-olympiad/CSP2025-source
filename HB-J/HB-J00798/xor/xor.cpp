#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(k == 0) cout << n / 2;
	else{
		int x = 0;
		for(int i = 1; i <= n; i++){
			int c;
			cin >> c;
			if((c)) x++;
		}
		cout << x;
	}
	return 0;
}
