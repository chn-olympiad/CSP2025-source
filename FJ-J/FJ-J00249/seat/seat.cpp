#include<bits/stdc++.h>
using  namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,b,nx=0,m,l,a[100],s,x;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		s++;
	}
	x=a[0];
	for(int i=1;i<s;i++){
		if(a[i]<x){
			nx++;
		}
	}
	b=s-nx-1;
	
	if(b>=n){
	while(b-n<0){
		b-=n;
		l++;
	}
	if(b==0){
	if((l+1)%2!=0){
			cout<<l<<" "<<1;
			return 0;
		}else{
			cout<<l<<" "<<n;
			return 0;
		}
	} 
}else if(b<n&&b!=0){
	cout<<"1"<<" "<<b;
	return 0; 
} 	
	if((l+1)%2!=0&&b!=0){
		cout<<l+1<<" "<<b+1;
		return 0;
	}else{
			cout<<l+1<<" "<<n-b;
			return 0;
	}
	return 0;
} 
