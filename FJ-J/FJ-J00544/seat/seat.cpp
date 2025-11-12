#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],r,fx,fy,k=1;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1; j<=m; j++) {
		if(j%2==1) {
			for(int i=1; i<=n; i++) {
				b[i][j]=a[k];
				k++;
			}
		} else {
			for(int i=n; i>=1; i--) {
				b[i][j]=a[k];
				k++;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(b[i][j]==r) {
				fx=i;
				fy=j;
				break;
			}
		}
	}
	cout<<fy<<' '<<fx;
	return 0;
}
