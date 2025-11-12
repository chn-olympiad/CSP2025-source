#include<bits/stdc++.h>
using namespace std;
int n,m,R,seat;
bool f=0;
int pos;
int a[110];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	R=a[1];	
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==R)pos=i;
	}
	for(int i=1; i<=n; i++) {
		if(f==0) {
			for(int j=1; j<=m; j++) {
				seat++;
				if(seat==pos) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
			f=1;
			continue;
		}
		if(f==1) {
			for(int j=m; j>=1; j--) {
				seat++;
				if(seat==pos) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
			f=0;
			continue;
		}
	}
	return 0;
}
