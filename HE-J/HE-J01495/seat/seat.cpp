#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c,r,x,y;
	int a[1000];
	cin>>n>>m;
	for(int i=0;i<1000;i++){
		a[i]=0;
	}
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	y=a[1];
	for(int i=1;i<=m*n;i++){
		for(int j=i+1;j<=m*n;j++){
		   if(a[i]<a[j]){
		      x=a[j];
			  a[j]=a[i];
			  a[i]=x;
	     	}
	    }
	}
	for(int i=1;i<=m*n;i++){
		if(a[i]==y){
			if(i%n==0){
				c=i/n;
				if(i/n%2==0){
					r=1;
				}else{
				  r=m;	
				}
			}else{
				c=i/n+1;
				if((i/n+1)%2==0){
				  r=m-(i%n-1);	
				}else{
				    r=i%n;	
				}
				
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
} 
