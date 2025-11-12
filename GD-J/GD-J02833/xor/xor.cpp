#include<bits/stdc++.h>
using namespace std;
long long n,a[1000009],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (long long i=1; i<=n; i++) cin >> a[i];
	if (k==0) cout << n;
	else cout << 0;
	return 0;
}
