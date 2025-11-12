#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s,p,c,r,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		if(a[i]==s){
			p=num-i+1;
		}
	}
	if(p%n==0){
		c=p/n;
	}
	else{
		c=p/n+1;
	}
	if(c%2==0){
		r=n-p%n+1;
	}
	else{
		if(p%n==0){
			r=n;
		}
		else{
			r=p%n;
		}
	}
	cout<<c<<" "<<r;
}
