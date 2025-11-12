#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,max=0,two=0,three=0,min=0,c,r,xr;
	cin>>n>>m;
	cin>>xr;
	for(int i=0;i<n*m-1;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n*m;i++){
		if(a[i]>max){
			max=a[i];
		}
		else if(a[i]>two){
			two=a[i];
		}
		else{
			three=a[i]; 
		} 
	}
	if(xr>max){
		c=1;
		r=1;
	}
	else if(xr>two){
		c=1;
		r=2;
	}
	else if(xr>three){
		c=2;
		r=2;
	}
	else{
		c=2;
		r=1;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
