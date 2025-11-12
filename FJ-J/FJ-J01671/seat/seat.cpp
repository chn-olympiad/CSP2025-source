#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,d;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int b=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[i]<a[j]){
			int x=a[i];
			a[i]=a[j];
			a[j]=x;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			d=i+1;
		}
	}
	int c,r;
	if(d%n==0){
		if((d/n)%2==0){
			r=1;
			c=d/n;
		}
		else{
			r=n;
			c=d/n;
		}
	}
	else{
		if((d/n+1)%2==0){
			r=n-d%n+1;
			c=d/n+1;
		}
		else{
			r=d%n;
			c=d/n+1;
		}
	}
	cout<<c<<" "<<r; 
	return 0;
} 
