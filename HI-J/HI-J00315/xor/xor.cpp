#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], maxa, cnt;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	if (k == 0) {
		cout<<0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
		if (a[i] == 1) {
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
