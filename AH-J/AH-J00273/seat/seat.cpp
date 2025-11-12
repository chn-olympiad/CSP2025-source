#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 1e2 + 5;
int n,m,a[SIZE];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n*m; i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	int p=0;
	for (int i=n*m; i>=1; i--) {
		if (a[i]==x) {
			p=n*m-i+1;
			break;
		}
	}
	if (p/n%2==0) {
		if (p%n==0) cout<<p/n<<" "<<1;
		else cout<<p/n+1<<" "<<p%n;
	}
	else {
		if (p%n==0) cout<<p/n<<" "<<n;
		else cout<<p/n+1<<" "<<n-p%n+1;
	}
	return 0;
}
