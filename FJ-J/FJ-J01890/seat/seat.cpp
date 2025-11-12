#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m; i>=1; i--) {
		if(a[i]==r) {
			int s=(n*m-i)/n;
			i=n*m-i+1-(n*m-i)/n*n;
			if(s%2==0) cout<<s+1<<" "<<i;
			else cout<<s+1<<" "<<n-i+1;
			return 0;
		}
	}
	return 0;
}
