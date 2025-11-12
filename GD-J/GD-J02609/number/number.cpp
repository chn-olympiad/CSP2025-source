#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[15];
char c[N];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c + 1);
	int n = strlen(c + 1);
	for(int i = 1; i <= n; i++){
		if(c[i] >= '0' && c[i] <= '9'){
			int x = int(c[i] - '0');
			a[x]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		int x = a[i];
		for(int j = 1; j <= x; j++) printf("%d", i);
	}
	return 0;
}
