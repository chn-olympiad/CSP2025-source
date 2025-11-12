#include <iostream>
#include <algorithm>
using namespace std;

int n,m,p,c,r;
int a[105];

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++)
		if(a[i]==p) {
			p=i;
			break;
		}
	c=p/n+(p%n>0);
	if(c&1) {
		if(p%n==0) r=n;
		else r=p%n;
	}
	else {
		if(p%n==0) r=1;
		else r=n-p%n+1;
	}
	cout<<c<<' '<<r;
	return 0;
}

