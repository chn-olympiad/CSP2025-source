#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[20][20];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	cin>>R;
	for(int i=1; i<n*m; i++) {
		cin>>a[i];
	}
	a[n*m]=R;
	sort(a,a+n*m+1);
	reverse(a,a+n*m+1);
	int tmp=0;
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				b[j][i]=a[tmp++];
			}
		} else {
			for(int j=n; j>=1; j--) {
				b[j][i]=a[tmp++];
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int i1=1; i1<=m; i1++) {
			if(b[i][i1]==R) {
				cout<<i1<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}