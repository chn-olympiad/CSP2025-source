#include <bits/stdc++.h>
using namespace std;
int n,m,mubiao,pai;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int a[n*m];
	cin >> mubiao;
	a[1] = mubiao;
	for(int i = 2; i<=n*m; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i = 1; i<=n*m; i++) {
		if(a[i] == mubiao) {
			pai = n*m-i+1;
		}
	}

	if((pai/n)%2==0) {
		if(pai%n==0) {
			cout << pai/n << " " << 1;
		} else {
			cout << (pai/n)+1 << " " << pai%n;
		}
	} else {
		if(pai%n==0) {
			cout << pai/n << " " << n;
		} else {
			cout << (pai/n)+1 << " " << n-pai%n+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
