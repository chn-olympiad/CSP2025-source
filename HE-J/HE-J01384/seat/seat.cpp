#include <bits/stdc++.h>
using namespace std;
int a[150],m,n,c,k,l,f;
int main() {
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m; i>=1; i--) {
		if(a[i]==c) {
			k=n*m-i+1;
		}
	}
	if(k%n==0) {
		l=k/n;
	} else {
		l=k/n+1;
	}
	f=k%n;
	if(f==0) {
		f=n;
	}
	if(l%2==0){
		f=f+n-1;
	}
	cout<<l<<" "<<f;
fclose(stdin);
fclose(stdout);
	return 0;
}
