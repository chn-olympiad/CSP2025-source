#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int s=n*m,k=1,xr;
	cin>>xr;
	for(int i=2;i<=s;i++){
		int x;
		cin>>x;
		if(x>xr)k++;
	}
	if(k%n==0) {
		c=k/n;
		if(c%2==0)r=1;
		else r=n;
	}
	else {
		c=k/n+1;
		if(c%2) r=k%n;
		else r=n-(k%n)+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
