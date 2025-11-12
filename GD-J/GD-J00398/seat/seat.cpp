#include<bits/stdc++.h>
using namespace std;
long long n,m,a[7500010],cnt=0,c,r;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<n*m; i++) {
		cin>>a[i];
		if(a[i]>=a[1]) {
			cnt++;
		}
	}
	if(cnt%n==0) {
		c=cnt/n;
	} else {
		c=cnt/n+1;
	}
	r=cnt%n;
	if(r==0) {
		r=n;
	}
	if(c%2==0) {
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
