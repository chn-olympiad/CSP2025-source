#include<bits/stdc++.h>
using namespace std;
int n, s=-1e5, a[5050], ans,f;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s=max(s,a[i]);
		ans+=a[i];
	}
    if(n<=3&&ans>2*s) cout<<1;
	else cout<<0;
	
	return 0;
}