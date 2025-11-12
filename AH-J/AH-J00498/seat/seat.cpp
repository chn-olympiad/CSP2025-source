#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q=-10000,p;
	cin>>n>>m;
	for (int k=1;k<=n*m;k++) {
		cin>>a[k];
	}
	for (int i=1;i<=n*m;i++) {
		for (int j=1;j<=n*m;j++) {
			if (a[j]>q) {
				q=a[j];
				p=j;
			}
			
		
		}
		
		if (q==a[1]) {
			
				if (i%n==0)cout<<i/n;
				else cout<<i/n+1;
				if (i/n%2==1 and i%n==0 ) cout<<" "<<i%n;
				else if ((i/n+1)%2==1 and i%n!=0) cout<<" "<<i%n;
				else cout<<" "<<(m+1)-i%n;
				return 0;
			}
		a[p]=-1;
		q=-100;
		
	}
	return 0;
}

