#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],b,c,d;

int main() {
	 freopen("seat.in","r",stdin);
	 freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			cin >> a[(i-1)*n+j];
		}
	}
	c=a[1];
	for (int i=1; i<=m*n-1; i++) {
		for (int j=i+1; j<=m*n; j++) {
			if(a[i]<a[j]) {
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}

	for (int i=1; i<=n*m; i++) {
		if(a[i]==c) {
			d=(i-1)/n+1;
			cout << d << " ";
			if(d%2==0){
				cout << d*n-i+1;
			} else {
				cout << i+n-d*n;
			} 
		}
	}
	return 0;
}
