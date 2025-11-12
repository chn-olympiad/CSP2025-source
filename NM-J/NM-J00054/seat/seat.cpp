#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,c,r;
	int q[110]={0};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>q[i];
	}
	int a=q[1];
	
	sort(q+1,q+1+m*n);
	for(int i=1;i<=n*m;i++){
		if(q[i]==a){
			x=m*n-i+1;
		}
	}
	if(x%n==0){
		c=(x/n);
	}
	else{
		c=(x/n)+1;
	}
	if(c>=2&&c%2==0){
		if(x%n==0){
			r=1;
		}
		else{
			r=n-x%n+1;
		}
	}
	else{
		if(x%n==0){
			r=n;
		}
		else{
			r=x%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
