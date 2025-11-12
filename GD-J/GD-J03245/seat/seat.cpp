#include<bits/stdc++.h> 
using namespace std;

int n, m, l[15][15], q[105], a;

bool cmp(int x, int y) {
	return x>y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin>>n>>m;
	cin>>a;
	
	for (int i=1;i<n*m;i++) {
		cin>>q[i-1];
	}
	
	sort(q, q+n*m-1, cmp);
	
	int p=n*m;
	
	for (int i=0;i+1<n*m;i++) {
		if (a>q[i]) {
			p=i+1;
			break;
		}
	}
	int k=(p+n-1)/n;
	if (k%2==1) {
		if (p%n) 
			cout<<k<<" "<<p%n;
		else cout<<k<<" "<<n;
	} else {
		if (p%n)
			cout<<k<<" "<<n+1-p%n;
		else cout<<k<<" "<<1;
	}
	
	return 0;
	
}
