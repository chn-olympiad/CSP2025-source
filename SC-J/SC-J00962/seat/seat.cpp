#include<bits/stdc++.h>
using namespace std;
long long a[205];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,s,d,cnt=0;
	cin>>n>>m;
	for(long long i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	for(long long i=1; i<=n*m; i++) {
		if(a[i]==s) {
			d=i;
			break;
		}
	}
	for(long long i=1; i<=m; i++) {
		if(i%2==1) {
			for(long long j=1; j<=n; j++) {
				cnt++;
				if(cnt==d){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		} else {
			for(long long j=n; j>=1; j--) {
				cnt++;
				if(cnt==d){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
