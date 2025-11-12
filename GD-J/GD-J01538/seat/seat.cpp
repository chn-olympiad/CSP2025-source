#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,k=1;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++) 
		for(int j=1,val;j<=m;j++) 
			if(!(i==1&&j==1)) cin>>val,k+=(val>x);
	for(int j=1;j<=m;j++) {
		if(j&1) {
			for(int i=1;i<=n;i++) {
				k--;
				if(!k) {
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else {
			for(int i=n;i>=1;i--) {
				k--;
				if(!k) {
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
}
