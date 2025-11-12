#include<bits/stdc++.h>
using namespace std;
int n,m,p,f=1;
int nm,a;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>p;
		if(i==1){
			a=p;
		}
		if(p>a){
			f+=1;
		}
	}

	c=f/n;
	r=f%n;
	if(r>0){
		c+=1;
	}else if(r==0){
		r=n;
	}
	if(c%2==1){
		cout<<c<<' '<<r;
	}else{
		r=n-r+1;
		cout<<c<<' '<<r;
	}


	return 0;
}
