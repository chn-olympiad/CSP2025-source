#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>=a[0])t++;
	}
	int b;
	if(t%n==0)b=t/n;
	else b=t/n+1;
	cout<<b<<" ";
	if(b%2==1){
		if(t%n==0)cout<<n;
		else cout<<t%n;
	}
	else{
		if(t%n==0)cout<<1;
		else cout<<n-t%n+1;
	} 
	
	return 0;
} 
