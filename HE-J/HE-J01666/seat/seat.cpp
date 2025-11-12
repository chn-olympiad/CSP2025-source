#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[200];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int sl=m*n;
	for(int i=1; i<=sl; i++) {
		cin>>b[i];
	}
	int ds=b[1];
	sort(b+1,b+1+sl,cmp);
	int n1=1;
	for(int i=1; i<=m; i++) {
		if(i%2!=0) {
			for(int j=1; j<=n; j++) {
				a[j][i]=b[n1];
				n1++;
			}
		}
		if(i%2==0) {
			for(int j=n; j>=1; j--) {
				a[j][i]=b[n1];
				n1++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(a[i][j]==ds) {
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
