#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int d;
	int c,r;
	int a1;
	int a2;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	int ans=0;
	bool w=1;
	for(int j=1;j<=n*m;j++){
		for(int i=1;i<=n*m;i++){
		    if(a[i]<=a[i+1] && i+1<=n*m){
			    d=a[i+1];
			    a[i+1]=a[i];
			    a[i]=d;
		    }
	    }
    }
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			a2=i;
		}
	}
	if(a2%n==0){
		c=a2/n;
	}else{
		c=a2/n+1;
	}
	if(a2%n==0){
		if(c%2==0) r=1;
		if(c%2==1) r=n;
	}else if(c%2==0){
		r=n-(a2%n)+1;
	}else if(c%2==1){
		r=a2%2;
	}
    
    cout<<c<<" "<<r;
	                                                                                                                                                                                                                                                                                                                                                                                                                                                         



	return 0;
}
