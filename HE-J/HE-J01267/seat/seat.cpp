#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	cnt = a[1];
	sort(a+1,a+1+n*m);
	for(int i = 1;i <= n*m;i++){
		b[n*m-i+1] = a[i];
	}
	for(int i = 1;i <= n*m;i++){
		if(b[i] == cnt) {
			if(i % (2*n) > n&& i % (2*n) > 0) cout << i/n+1 << ' ' << n-i%n+1;
			if(i % n==0) cout << i/n <<' '<< n;
			if(i % (2*n) == 0) cout << i/n << ' ' << 1;
			if(i % (2*n) < n && i % (2*n) > 0) {
				cout << i/n+1 << ' ';
				cout << i % n;
			}
			break;
		}
	}
	return 0;
}
