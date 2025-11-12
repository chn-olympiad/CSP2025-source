#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
char s;
int a[100005];
int k = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i =1; i <= 100005; i++){
		cin >> s;
		if ((int)s >=48 && (int)s <= 57){
			k++;
			a[k] = (int)s-48;
		}
		else continue;
	}
	while(1){
		bool p = 1;
		for (int i = 1; i <= k-1; i++){
			if (a[i] <a[i+1]){
				int m =a[i];
				a[i] = a[i+1];
				a[i+1]=m;
				p=0;
			}
		}
		if (p) break;
	}
	for (int i = 1; i <=k; i++) cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
