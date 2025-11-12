#include<bits/stdc++.h>
#define I using 
#define AK namespace 
#define CSP std
I AK CSP;
const int maxn=15;
int a[maxn];
int n,m;
int R_s;//Ð¡RµÄscore 
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	R_s=a[1];
	sort(a+1,a+1+(n*m),greater<int>());
	int r=0,c=0;
	for (int i=1;i<=n*m;i++) {
		if (a[i]==R_s) {
			if (i%n==0) c=i/n;
			else c=i/n+1;
			if (i%n==0) r=n;
			else r=i%n;
			if (!(c&1)) r=(n+1-r);
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
