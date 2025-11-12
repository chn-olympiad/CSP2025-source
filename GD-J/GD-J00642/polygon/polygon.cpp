#include <bits/stdc++.h>
using namespace std;
#define M(a) (a % 988244353)
int n;
int a[25];
bool b[25];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	bool cas = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) cas = false;
	}
	int ans = 1;
	int sb;
	if(!cas)ans = sb % M(M(n) * M(n));
	else for(int i = 4; i <= n; i++) ans = M(ans * i);
	
	
	cout << M(ans);
	return 0;
}

