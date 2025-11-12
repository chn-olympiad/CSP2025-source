#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seatr.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+5];
	int b=0;
	int c=0,r=0;
	for(int i=0;i<n*m;i++ ){
		cin>>a[i];
		if(a[i]>a[0]) b++;
	}
	c=b/n;

	if(c%2==0){
		r=b%n+1;
	}
	else{
		r=n-b%n;
	}	
	c++;
	cout<<c<<" "<<r;
	return 0;
} 
