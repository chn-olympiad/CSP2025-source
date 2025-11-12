#include<bits/stdc++.h>
using namespace std;
long long hyc[400];
int main() {
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long hh;
	for(long long i=1; i<=n*m; i++) 
		cin>>hyc[i];
	hh=hyc[1];
	long long ddd=n*m+1;
	sort(hyc+1,hyc+ddd);
	for(long long i=1; i<=n; i++) {
		if(i%2==1) {
			for(long long j=1; j<=n; j++) {
				ddd--;
				if(hyc[ddd]==hh) {
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		} else {
			for(long long j=n; j>=1; j--) {
				ddd--;
				if(hyc[ddd]==hh) {
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
