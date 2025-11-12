#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char c[N];
int a[N], tot;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> c;
	int len = strlen(c);
	for (int i = 0; i < len; i++){
		if (c[i] >= '0' && c[i] <= '9'){
			tot++;
			a[tot] = c[i] - 48;
		}
	}
	sort(a+1, a+1+tot, cmp);
	if (a[1] == 0){
		cout << "0";
		return 0;
	}
	for (int i = 1; i <= tot; i++){
		cout << a[i];
	}
	
	return 0;
}
