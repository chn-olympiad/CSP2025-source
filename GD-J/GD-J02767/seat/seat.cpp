#include<bits/stdc++.h>
using namespace std;
int b[15][15],n,m;
struct node {
	int t;
} a[105];
bool cmp(node x,node y) {
	return x.t>y.t;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].t;
	}
	int r=a[1].t;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				b[j][i]=a[(i-1)*n+j].t;
			}
		}
		if(i%2==0) {
			for(int j=n; j>=1; j--) {
				b[j][i]=a[(i-1)*n+n-j+1].t;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(r==b[i][j]) {
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
