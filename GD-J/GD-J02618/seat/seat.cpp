#include<bits/stdc++.h>
using namespace std;
int seat[105],n,m,l1,r,c,p;
int sh(int a){
	int r=n*m,l=1,g;
	while(r!=l){
		g=(r+l)>>1;
		if(seat[g]>a) r=g;
		else if(seat[g]<a) l=g;
		else return g;
	}
	return r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>seat[1];
	l1=seat[1];
	for(int i=2;i<=n*m;i++){
		cin>>seat[i];
	}
	sort(seat,seat+n*m+1);
	p=n*m-sh(l1)+1;
	c=(p+n-1)/n;
	if(c%2==0) r=n-(p-c*n+n)+1;
	else r=(p-c*n+n);
	cout<<c<<' '<<r;
	return 0;
} 
