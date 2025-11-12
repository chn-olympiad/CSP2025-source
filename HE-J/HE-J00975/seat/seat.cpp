#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,n,m,num;
	cin>>n>>m;
	int w=n*m;
	int a[w],i;
	while(a[i]!='\n'){
		cin>>a[i];
		i++;
		break;
	}
	if(a[0]<=n){
		c=num;
		r=1;}
	else if(a[0]<=(2*n)){
			c=2*num;
			r=2;}
	cout<<c<<r;
	return 0;
}
