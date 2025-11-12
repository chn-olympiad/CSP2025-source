#include<bits/stdc++.h>
using namespace std;
long long a[54088],n,m,c,r,s,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	s=a[0];
	for(int i=0;i<n*m-1;i++){
		for(int e=i+1;e<n*m;e++){
			if(a[e]>a[i]){
				z=a[i];
				a[i]=a[e];
				a[e]=z;
			}
		}
	}
	z=0;
	for(int i=0;i<n*m;i++){
	    z++;
		if(s==a[i]){
			break;
		}	
	}
	s=2*n;
	if(z%n!=0){
		c=z/n+1;
	}else{
		c=z/n;
	}
	if(z%s!=0){
		r=z%s;
		if(r>n){
			r=s-r+1;
		}
	}else{
		r=z%s+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

