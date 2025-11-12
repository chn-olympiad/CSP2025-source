#include<bits/stdc++.h>
using namespace std;
int n,m,a[105][105],c=0,b[10050],v=0;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			c++;
			cin>>a[i][j];
			b[c]=a[i][j];
		}
	}
	v=a[1][1];
	sort(b+1,b+c+1);
	for(int i=1; i<=m; i++) {
		if(i%2==0) {
			for(int j=n; j>=1; j--) {
				if(b[c]==v) {
					cout<<i<<" "<<j;
					return 0;
				}
				c--;
			}
		} else {
			for(int j=1; j<=n; j++) {
				if(b[c]==v) {
					cout<<i<<" "<<j;
					return 0;
				}
				c--;
			}
		}
	}
	return 0;
}
