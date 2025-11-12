#include<bits/stdc++.h>
#include<iostream>
using  namespace std;
int n,m,a,b,p,q=1,x,y;
int main{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	cin>>a;
	for(int i=1;i<n*m;i++){
	cin>>b;
	if(b>a)q++;
	}
	x=q%(2*n);
	y=(q-x)/n+1;
	if(x>n)cout<<y+1<<' '<<x-n;
	else if(x==0)cout<<y+1<<' '<<n;
	else cout<<y<<' '<<x;
	return 0;
}
