#include<bits/stdc++.h>
using namespace std;
long long n,m,a,num=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m*n;i++){
		long long x;
		cin>>x;
		if(i==1){
			a=x;
		}
		else{
			if(a<x){
				num++;
			}
		}
	}
	c=num/n;
	r=num%n;
	if(r==0){
		r=n;
	}
	else{
		c++;
	}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<' '<<r;
	return 0;
} 
