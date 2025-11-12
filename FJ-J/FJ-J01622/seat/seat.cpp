#include <bits/stdc++.h>
using namespace std;

int n,m,x,q=1;
int tmp;

int main() {
	freopen ("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=2; i<=n*m; i++) {
		cin>>tmp;
		if(tmp>x) q++;
	}
	int x=ceil(q/(2*n)*1.0),y=q%(2*n);
	if(y<=n) {
		cout <<2*x+1 <<" "<<y<<endl;
	} else {
		cout <<2*(x+1)<<" "<<2*n-y+1<<endl;
	}
	
	return 0;
}
