#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) {
		cin >> a[i];
	}
	int p=a[1],k=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i]==p) {
			k=i;
			break;
		}
	}
	if(k<n) {
		cout << 1 << ' ' << k;
	}else if(k>n) {
		int v=k/n+1;
		if(v&1) {
			int t=k%n;
			cout << v << ' ' << t;
		}else {
			int s=n-k%n+1;
			cout << v << ' ' << s;
		}
	}else {
		cout << k/n << ' ' << n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
