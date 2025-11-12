#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ls,a[111];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	ls=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++) {
		if(i%2==1) {
			for(int j=1;j<=n;j++) {
				if(ls==a[k--]) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else {
			for(int j=n;j>=1;j--) {
				if(ls==a[k--]) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
