#include<bits/stdc++.h>
using namespace std;
int n,m,j=0,k=0,c=0,r=0,l=0;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	j=a[1];
	for(int i=1;i<=l;i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);	
		}
	}
	for(int i=1;i<=l;i++){
		if(a[i]==j){
			k=i;
		}
	}
	if(k==n){
		c=1;
		r=n;
	}
	if(k<n){
		c=1;
		r=k;
	}
	if(k%n==0){
		c=k/n;
		r=n;
	}
	if(k>n){
		c=k/n+1;
		r=n-k%n;
	}
	if(k>2*n){
		c=k/n+k%n;
		r=k%n;
	}
	cout<<c<<' '<<r;
	return 0;
}

