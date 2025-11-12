#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],id,l,h;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int s=a[1];
	stable_sort(a+1,a+n*m+1);
	for(int i=n*m; i>=1; i--) {
		++id;
		if(a[i]==s) {
			break;
		}
	}
	if(id%n==0) {
		l=id/n;
	} else {
		l=id/n+1;
	}
	if(l%2) {
		h=id-n*(l-1);
	} else {
		h=n-(id-n*(l-1))+1;
	}
	cout<<l<<" "<<h;
}
