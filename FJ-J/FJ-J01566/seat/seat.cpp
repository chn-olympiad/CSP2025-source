#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1000000],b=1,c=0,d=0;
	cin>>n>>m;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++){
		if(a[1]<a[i]){
			b++;
		}
	}
	if(b%n==0){
		c=b/n;
	}else{
		c=b/n+1;
	}
	if(c%2==0){
		d=n-b%n+1;
	}else{
		if(b%n==0){
			d=n;
		}else{
			d=b%n;
		}	
	}
	cout<<c<<" "<<d;
	return 0;
}
