#include <bits/stdc++.h>
using namespace std;
int ans=1;
int k[2];
int n,m,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k[0];
	for(int i=0;i<n*m-1;i++){
		cin>>k[1];
		if(k[1]>k[0]) ans++;
	}
	if(ans%n!=0) c=ans/n+1;
	else c=ans/n;
	if(c%2==1){
		r=ans%n;
		if(r==0) r=n;
	}
	else{
		r=n-ans%n+1;
		if(ans%n==0) r=1;
	}
	cout<<c<<" "<<r;
} 
