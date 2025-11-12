#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m,r=0,c=0,b,a;
	cin>>n>>m;
	int x;
	x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a;
		if(i==1){
			a=b;
		}
		if(a>b){
			c=c+1;
		}
	}
	c=c+1;
	if(c>n){
		if(c%n==0){
			r=c/n;
			if(r%2==0){
				c=1;
			}else{
				c=n;
			}
		}else{
		r=c/n+1;
		if(r%2==0){
		    c=c-(r-1)*n;
	    }else{
		    c=c-(r-1)*n+1;
	    }
	}

	}else{
		r=1;
	}
	
	    

	cout<<r<<" "<<c;
	return 0;
}









