#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m;
int a[N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	int pos=1;
	for(int i=2;i<=n*m;i++) {
		if(a[i]>a[1]) {
			pos++;
		}
	}
	int c=ceil((double)pos/(double)n);
	int r=pos%n;
	if(r==0) r=n;
	if(c&1) cout<<c<<" "<<r;
	else cout<<c<<" "<<n-r+1;
	return 0;
}
