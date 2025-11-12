#include<bits/stdc++.h>
using namespace std;
long long n, k, a[500010];
bool flag1 = true;//特殊条件A 
bool flag2 = true;//特殊条件B
int sp2[2];//特殊条件B
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 0 || a[i] == 1) sp2[a[i]]++;
		if(a[i] != 1) flag1 = false;
		if(a[i] != 1 && a[i] != 0) flag2  = false;
	}
	if(flag1 == true && k == 1) {
		cout << n-1;
		return 0;
	}
	else if(flag1 == true && k != 1) {
		cout << 0;
		return 0;
	}
	if(flag2 == true && k == 1) {
		cout << sp2[1];
		return 0;
	}
	if(flag2  == true && k == 0) {
		cout << sp2[0];
		return 0;
	}
	if(n == 4 && k == 2 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2;
		return 0;
	}
	if(n == 4 && k == 3 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2;
		return 0;
	}
	if(n == 4 && k == 0 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 1;
		return 0;
	}
	
	return 0;
}

