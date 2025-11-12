#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin >> a >> b;
	short c[a];
	bool ok = 1;
	int x = 0;
	int y = 0;
	if (b > 1){
		cout << b; 
		return 0;
	}
	for (int i = 0;i < a;i++){
		cin >> c[i];
			if (c[i] == 0){
				ok = 0;
				x++;
			}else{
				y++;
		}
	}
	if(ok && b == 0){
		cout <<0;
		return 0;
	}
	if (ok && b == 1){
		cout << a;
		return 0;
	}
	if (b <= 1 && ok == 0){
		if (b == 0){
			cout << x;
		}else{
			cout << y;
		}
	}
} 
