#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long a;
	a = 1;
	int n;
	cin >>n;
	for(int i = 1; i <= n; i++) {
		a = a*i % 998244353;

	}
	cout << a << endl;
	return 0;
}
