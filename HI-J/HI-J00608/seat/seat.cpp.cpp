#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=0,c=1,x=0,z=0;
	cin>>n>>m;
	int a[n*m]={},b[n*m]={};
	for(int i=0; i<n*m; i++){
		cin>>a[i];
	}
	sum=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1; i>=0; i--){
		b[x]=a[i];
		z++;
		if(z>n){
			c++;
			z=1;
		}
		if(b[x]==sum){
			if(c%2==0){
				cout<<c<<" "<<n-z+1;
				return 0;
			}else {
				cout<<c<<" "<<z;
			}
			return 0;
		}
		x++;
	}
	return 0;
} 
