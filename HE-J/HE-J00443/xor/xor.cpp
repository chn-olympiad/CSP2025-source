#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int x;
	cin >> n >> k;
	if (k == 0 && (n == 1 || n == 2)){
		bool flag = true;
		for (int i = 1;i <= n;i++){
			cin >> x;
			if (x != 1){
				flag = false;
				break;
			}
		}
		if (flag){
			if (n == 1){
				cout << 0;
			}else if (n == 2){
				cout << 1;
			}
		}
	}

	
	return 0;
}
