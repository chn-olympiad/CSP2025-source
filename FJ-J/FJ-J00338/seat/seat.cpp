#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];

int wz_n(int x) {
	if (x<=n) return x;
	int t1,t2,t3;
	if ((x/n)%2==0) {
		t1=1;
		t2=1;
	}
	else {
		t1=n;
		t2=-1;
	}
	if (x%4==0) return t1;
	return t1+(x%n-1)*t2;
}

int wz_m(int x) {
	return (x-1)/m+1;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n*m; i++) {
		cin >> a[i];
	}
	int b=a[1];
	sort(a+1,a+n*m+1);
	for (int i=1; i<=n*m; i++) {
		if (a[i]==b) {
			cout << wz_m(n*m-i+1) << ' ' << wz_n(n*m-i+1);
			break;
		}
	}
	return 0;
}
