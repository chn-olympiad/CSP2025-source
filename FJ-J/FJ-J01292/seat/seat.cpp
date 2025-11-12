#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int gra;
	int who;
}a[105];
bool cmp(node x,node y) {
	return x.gra>y.gra;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++) {
		cin>>a[i].gra;
		a[i].who=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int rw;
	for(i=1;i<=n*m;i++) {
		if(a[i].who==1) rw=i;
	}
	int c,r;
	if(rw%n==0) {
		c=rw/n;
	}else c=rw/n+1;
	if(c%2==0) {
		if(rw%n==0) {
			r=1;
		}else r=n-rw%n+1;
	}else {
		if(rw%n==0) {
			r=n;
		}else r=rw%n;
	}
	cout<<c<<" "<<r;
	return 0;
}