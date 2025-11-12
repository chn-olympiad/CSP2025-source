#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10000],num=0,c=0;
	cin>>n>>m;
	int z=n*m;
	int x=z;
	for(int i=1;i<=z;i++){
		cin>>a[i];
		num=a[1];
		if(num>a[i])
		{
			x--;
		}
		
	}
	if(x!=n){
		c=x/n+1;	
	}
	else{
		c=x/n;
	}
	cout<<c<<" ";
	if(x<=n){
		cout<<c;
	}
	else if(x<=2*n){
		cout<<2*n-x+1;
	}
	else if(x<=3*n){
		cout<<x-2*n;
	}
	else if(x<=4*n){
		cout<<4*n-x+1;
	}
	else if(x<=5*n){
		cout<<x-4*n;
	}
	else if(x<=6*n){
		cout<<6*n-x+1;
	}
	else if(x<=7*n){
		cout<<x-6*n;
	}
	else if(x<=8*n){
		cout<<8*n-x+1;
	}
	else if(x<=9*n){
		cout<<x-8*n;
	}
	else if(x<=10*n){
		cout<<10*n-x+1;
	}
	
	
	
	
	return 0;
} 
