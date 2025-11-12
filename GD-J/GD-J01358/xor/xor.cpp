#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int maxn = a[1];
	for(int i = 2; i <= n; i++) maxn = max(maxn, a[i]);
	cout << maxn;
	return 0;
}
