#include<bits/stdc++.h>
using namespace std ;
int tong[10];
int up(int n , int m){
	if(n%m!=0){
		return n/m+1;
	}
	else{
		return n/m;
	}
}		
int main()
{
	
	freopen("seat.in","r" ,stdin);
	freopen("seat.out","w" ,stdout);
	int n,m,xs[150],cj,da=0;
	bool zn=0;
	cin>>n>>m;
	cin>>cj;
	for(int i=2;i<n*m;i++){
		cin>>xs[i];
		if(xs[i]>cj){
			da++;
		}	
	}
	da++;
	cout<<up(da,n)<<' ';
	if(up(da,n)%2!=0){
		if(da%n==0){
			cout<<n;
		}
		else{
			cout<<da%n;
		}	
	}
	else{
		if(da%n==0){
			cout<<1;
		}
		else{
			cout<<n-da%n+1;
		}	
	}		
	return 0;
}	
