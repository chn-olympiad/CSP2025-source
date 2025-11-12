#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105],cj,mc,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){ 
		cin>>a[i];
		if(i==1) cj=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj) mc=n*m-i+1;
	}
	c=ceil(mc*1.0/n);
	if(c%2==1){
		if(mc%n) r=mc%n;
		else r=n;
	}else{
		r=n-mc%n+1;
	}
	cout<<c<<" "<<r; 
}
