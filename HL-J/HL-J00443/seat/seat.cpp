#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],p,r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==p){
			p=n*m+1-i;
		}
	}
	r=p/n;
	c=p%n;
	if(r%2==0){
		if(r*n==p){
			cout<<r<<" "<<1;
		}else{
			cout<<r+1<<" "<<c;
		}
	}else{
		if(r*n==p){
			cout<<r<<" "<<n;
		}else{
			cout<<r+1<<" "<<n+1-c;
		}		
	}
	return 0;
}
