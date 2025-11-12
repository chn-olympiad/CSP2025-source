#include<bits/stdc++.h>
using namespace std;
char x;
int a[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while(cin >> x){
		int y = int(x - '0');
		if('0' <= x && x <= '9') a[y]++;
	}
	bool flag = 1;
	for (int i = 9; i >= 0; i--){
		if (i == 0 && flag){
			printf("%d", i);
			break;
		}
		if (a[i] != 0){
			for (int j = 1; j <= a[i]; j++) printf("%d", i);
			flag = 0;
		}
	}
	return 0;
}
