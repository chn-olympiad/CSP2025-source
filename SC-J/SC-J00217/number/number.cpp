#include<bits/stdc++.h>
using namespace std;
string a;
int x[1000010], p;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int n = a.length();
	for (int i = 0; i < n; i++){
		if (a[i] >= '0' && a[i] <= '9'){
			x[++p] = a[i] - '0';
		}
	}
	sort(x+1, x+p+1);
	for (int i = p; i >= 1; i--)
		cout << x[i];
	return 0;
}