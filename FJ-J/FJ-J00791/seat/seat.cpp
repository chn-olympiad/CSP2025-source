#include<bits/stdc++.h> 
using namespace std;
int main(){
	int a[105],b[105],m,n,c,r,xm,xmxb;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	for(int i=0;i<z;i++){
		cin>>a[i];
		if(i==0)xm=a[i];
	}
	for(int i=0;i<=z;i++){
		int max=0,xbmax=0;
	    for(int j=0;j<=z;j++){
		    if(a[j]>=max){
		    	max=a[j];
		    	xbmax=j;
	    	}
	    }
	    b[i]=max;
	    if(b[i]==xm)xmxb=i;
	    a[xbmax]=0;
	}
	if(xmxb%n>0)c=xmxb/n+1;
	else c=xmxb/n;
	if(c%2==0){
		if(xmxb%n>0)r=n-xmxb%n+1;
	    else r=1;
	}
	else{
		if(xmxb%n>0)r=xmxb%n;
	    else r=n;
	}
	cout<<c<<" "<<r;
	return 0;
}
