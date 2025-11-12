#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int a[maxn];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int s=n*m;
	for(int i=1;i<=s;i++) {
		int x;
		cin >> x;
		a[i]=-x;
	}
	int ans=a[1],id;
	sort(a+1,a+s+1);
	for(int i=1;i<=s;i++) {
		if(a[i]==ans) {
			id=i;
			break;
		}
	}
	int c,r;
	if(id%n==0) {
		c=id/n;
		if(c%2==0) r=1;
		else r=n;
	}else {
		c=id/n+1;
		int b=id%n;
		if(c%2==0) r=n-b+1;
		else r=b;
	}
	cout << c << " " << r << "\n";
	return 0;
}
