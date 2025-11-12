#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],x,xy;
int cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==x) {
			xy=i;
			break;
		}
	}
	int d=xy;
	int dd=d/n;
	if(xy%n!=0) {
		cout<<dd+1<<" ";
		if(dd%2==0) {
			cout<<d%n;
		} else {
			int yy=dd+1;
			yy*=n;
			cout<<yy-d+1;
		}
	} else {
		cout<<dd<<" ";
		if(dd%2==0) {
			cout<<1;
		} else cout<<n;
	}
	return 0;
}
