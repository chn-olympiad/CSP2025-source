#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,c,r=1,a1,nm;
int main(){

	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=n*m;i++)
	    cin>>a[i];
	a1=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	  if(a1==a[i])nm=n*m-i+1;
	r=nm%(n*2);
	if(r>n){r=2*n-r+1;}
	if(nm%n){c=nm/n+1;}
	if(nm%n==0){c=nm/n;}
	cout<<c<<" "<<r;
	return 0;
} 