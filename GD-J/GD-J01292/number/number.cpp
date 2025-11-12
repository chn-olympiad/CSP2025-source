#include <bits/stdc++.h>
using namespace std;
char c[1000005]; int a[10], i, f;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> c;
	for(int i = 0; i < strlen(c); i++){
		if (isdigit(c[i])) a[(int)c[i] - 48]++;
	}
	for (int i = 1; i < 10; i++){
		if (a[i]) f = 1;
	}
	if (!f) printf("0");
	else for (int j = 9; j >= 0; j--) for (int i = 1; i <= a[j]; i++) printf("%d", j);
	return 0;
}
