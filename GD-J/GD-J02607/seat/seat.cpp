#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, id=0;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m>>y;
	for(int i=2; i<=n*m; i++) {
		cin>>x;
		if(y<x) id++;
	}
	int l=id%n+1, r=id/n+1;
	if(r%2==0) l=n-l+1;
	cout<<r<<" "<<l;
	return 0;
}
