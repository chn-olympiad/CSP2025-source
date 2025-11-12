#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r,flag,k,vis;
int a[1005];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	flag=1,c=1,r=1,k=a[1];
	sort(a+1,a+1+n*m,cmp);
	if(n==1) {
		for(int i=1; i<=n*m; i++) {
			if(k==a[i]) {
				cout<<c<<" "<<r<<endl;
				return 0;
			} else {
				c++;
			}
		}
		return 0;
	} else if(m==1) {
		for(int i=1; i<=n*m; i++) {
			if(k==a[i]) {
				cout<<c<<" "<<r<<endl;
				return 0;
			} else {
				r++;
			}
		}
		return 0;
	}
	for(int i=1; i<=n*m; i++) {
		if(k==a[i]) {
			cout<<c<<" "<<r<<endl;
			return 0;
		}
		if(r==n&&vis!=0) {
			flag=-1;
			c++;
			vis=0;
		} else if(r==1&&vis!=0) {
			flag=1;
			c++;
			vis=0;
		} else {
			r+=flag;
			vis=1;
		}
	}
	return 0;
}
