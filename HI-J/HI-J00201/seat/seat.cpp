#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(long long i=0;i<n*m;i++){
		cin>>a[i];
	} 
	int xr=a[0];
	for(long long i=0;i<n*m;i++){
		for(long long j=i+1;j<n*m;j++){
			if(a[j]>a[i]){
				int jh=0;
				jh=a[i];
				a[i]=a[j];
				a[j]=jh;
			}
		}
	}
	int xb=0;
	for(long long i=0;i<n*m;i++){
		if(xr==a[i]){
			xb=i+1;
		}
	}  
	if(xb<=n){
		cout<<1<<" "<<xb;
		return 0;
	}
	
	int c=1;
	c+=xb/n;
	if(c>m){
		c=m;
	}
	int xxbb=xb;
	if(xb-c*n<=0){
		xb+=n-1;
	}
	xb-=c*n;
	
	if(c%2==0){
		
		cout<<c<<" "<<m-xb;
	}
	if(c%2!=0){
		xb++;
		cout<<c<<" "<<xb;
	}
	return 0;
} 
