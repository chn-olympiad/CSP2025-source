#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,z,R,C,c=1,r=1,g=1;
	cin>>n>>m;
	z=n*m;
	for(int i=0;i<z;i++){
		cin>>a[i];
	}
	R=a[1];
	while(z--){
	g++;
	if(R<a[g]){
		r++;
	}
}
	C=r;
	
	if(C>n){
		r=r-(r-m);
	}

	
		if(C>=m){ 
		if(C%m){
			c=C/m;
			floor(c);
			c--;
		}else{
			c=C/m;
			floor(c);
			c++;
		}
	}
	
	cout<<c<<" "<<r;
	
	return 0;
}
