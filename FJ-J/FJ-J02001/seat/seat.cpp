#include<bits/stdc++.h>
using namespace std;
int n,m,a,k,s=1,r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>k)s++;
	}
	c=(s+n-1)/n;
	r=s-n*c+n;
	if(c%2==0)r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
