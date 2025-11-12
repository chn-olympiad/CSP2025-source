#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a[99][99],b[101],c,e,d=1,r,n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>b[i];
		if(i==1) {
			c=b[i];
		}
	}
	for(int i=1; i<=n*m; i++) {
		for(int j=2; j<=n*m; j++) {
			if(b[j-1]<b[j])swap(b[j-1],b[j]);
		}
	}
	for(int i=1; i<=m; i++) {
		if(i%2!=0) {
			for(int j=1; j<=n; j++) {
				if(b[d]==c) {
					cout<<i<<" "<<j;
					break;
				}
				d=d+1;
			}
		} else {
			for(int j=n; j>=1; j--) {
				if(b[d]==c) {
					cout<<i<<" "<<j;
					break;
				}
				d=d+1;
			}
		}

	}
	return 0;
}
