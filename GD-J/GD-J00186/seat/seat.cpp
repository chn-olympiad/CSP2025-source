#include <bits/stdc++.h>
using namespace std;

struct people {
	int poin;
	int wz;
};

bool cmp (people x,people y) {
	return x.poin>y.poin;
}

int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int n,m;
	people a[105];
	
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) {
		cin>>a[i].poin;
		a[i].wz=i;
	}
	
	sort(a+1,a+n*m+1,cmp);
	
	for (int i=1;i<=n*m;i++) {
		if (a[i].wz==1) {
			if (i%n!=0) {
				cout<<i/n+1<<" ";
				if ((i/n+1)%2==0) {
					cout<<n-(i%n);
				} else {
					cout<<i%n;
				}
			} else {
				cout<<i/n<<" ";
				if ((i/n)%2==0) {
					cout<<n;
				} else {
					cout<<1;
				}
			}
		}
	}
	
	return 0;
}
