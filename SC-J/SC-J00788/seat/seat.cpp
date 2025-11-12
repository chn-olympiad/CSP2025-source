#include<bits/stdc++.h>
using namespace std;
int m,n,x,y,h,l;
int a[105],b,c=1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m*n; ++i) {
		cin>>a[i];
		b=a[1];
		if(a[i]>b) ++c;
	}
	x=c/n;
	y=c%n;
	if(y==0) {
		l=x;
	} else l=1+x;

	if(y==0) {
		
		if(l%2==1) {
			h=n;
		} else h=1;
		
	} else {
		
		if(l%2==1){
			h=y;
		}else h=n+1-y;
		
	}


	//cout<<n<<' '<<m;
	//cout<<c<<' '<<x<<' '<<y<<' ';
	cout<<l<<' '<<h;
	return 0;
}