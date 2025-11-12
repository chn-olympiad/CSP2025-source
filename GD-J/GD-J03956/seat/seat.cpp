#include<bits/stdc++.h>
using namespace std;
int n,m,r,pos,l,h,a[222];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			pos=n*m-i+1;
		}
	}
	l=(pos+n-1)/n;
	if(l%2==0) h=n-(pos-(l-1)*n)+1;
	else h=pos-(l-1)*n;
	cout<<l<<" "<<h;
	return 0;
} 
