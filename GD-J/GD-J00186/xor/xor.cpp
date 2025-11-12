#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int n,k,a[10005];
	
	cin>>n>>k;
	
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	
	if (n<=2) {
		cout<<n;
		return 0;
	}
	
	return 0;
}
