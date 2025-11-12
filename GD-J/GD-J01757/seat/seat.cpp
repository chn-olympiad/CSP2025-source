#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int m,n,c,r,a[1001],b[1001],a0,a0_;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	a0=a[0];
	sort(a,a+n*m);
	for(int i=1;i<=m*n;i++){
		b[i]=a[m*n-i];
		if(b[i]==a0)a0_=i;
	}
	int l=a0_/(2*n),p=a0_%(2*n);
	
	if(l==0){
		if(p==0){
			c=2*l;
			r=1;
		}
		if(p>n){
			c=2;
			r=n-(p-n)+1;
		}
		else{
			c=1;
			r=p;
		}
	}
	else if(p==0){
		c=2*l;
		r=1;
	}
	else if(p>n){
		c=2*l;
		r=n-(p-n)+1;
	}
	else{
		c=2*l+1;
		r=p;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
