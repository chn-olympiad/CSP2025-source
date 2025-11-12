#include <bits/stdc++.h>
using namespace std;
string r;
int a[1000005];
int step;
bool cmp(int a,int b){
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> r;
	for (int i=0; i<r.length(); i++) {
		if (r[i] == '0' || r[i] == '1' || 
		r[i] == '2' || r[i] == '3' || 
		r[i] == '4' || r[i] == '5' || 
		r[i] == '6' || r[i] == '7' ||
		r[i] == '8' || r[i] == '9') {
			int b = r[i]-'0';
			step++;
			a[step] = b;
		}
	}
	sort(a+1, a+1+step, cmp);
	if (a[1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i=1; i<=step; i++) {
		cout << a[i];
	}
	return 0;
}