#include<bits/stdc++.h>
using namespace std;
int a[150];
int b[15][15];
bool cmp(int &x,int &y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int r=a[1];
	for(int i=2; i<=n*m; i++) cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	int t=1,x=1,y=1;
	bool f=1;//1об0ио
	for(y=1; y<=m; y++) {
		if(f==1) {
			for(x=1; x<=n; x++) {
				b[x][y]=a[t];
				t++;
			}
			f=0;
		} else {
			for(x=n; x>=1; x--) {
				b[x][y]=a[t];
				t++;
			}
			f=1;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(b[i][j]==r) {
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
}
