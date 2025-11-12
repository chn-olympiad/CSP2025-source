#include<bits/stdc++.h>
using namespace std;
int n,m,k,xr;
int a[105];
int b[20][20];
bool cmp(int x,int y) {
	if(x>y) {
		return true;
	} else if(x<y) {
		return false;
	}
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z = n*m;
	for(int i=1; i<=z; i++) {
		cin>>a[i];
	}
	xr = a[1];
	sort(a+1,a+1+z,cmp);
	if(a[1] == xr){
		cout<<1<<" "<<1;
		return 0;
	}
	if(a[z] == xr){
		cout<<n<<" "<<m;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		if(i%2 == 1) {
			for(int j=1; j<=m; j++) {
				k++;
				b[i][j] = a[k];
			}
		} else if(i%2 == 0) {
			for(int j=m; j>=1; j--) {
				k++;
				b[i][j] = a[k];
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(b[i][j] == xr) {
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
