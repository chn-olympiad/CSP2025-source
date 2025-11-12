#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,c=1;
int a[105];
int b[15][15];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n*m; i++) {
		if(a[1]<=a[i]) {
			sum++;
		}
	}
	for(int i=1; i<=m; i++) {
		if(i%2==0) {
			for(int j=n; j>=1; j--) {
				b[i][j]=c++;
			}
		} else {
			for(int j=1; j<=n; j++) {
				b[i][j]=c++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(sum==b[i][j]){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
