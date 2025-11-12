#include<iostream>
using namespace std;
const int N = 128;

int n,m;
bool a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	int nm = n*m, R, p, hang, lie;
	cin>>R;
	a[R] = 1;
	for(int i=2, x;i<=nm;++i) {
		cin>>x;
		a[x] = 1;
	}
	for(int i=100;i>=R;--i) {
		if(a[i]) ++p;
	}
	lie = (p+n-1)/n;
	p %= n;
	if(p==0) p=n;
	if(lie&1) hang = p;
	else hang = n-p+1;
	cout<<lie<<' '<<hang;
	return 0;
}