#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,add,c,r,p,t=0,d;
	cin>>n>>m;
	int a[m*n];
	for(int i=0;i<=m*n-1;i++)
	{
		cin>>a[i];
	}
	p=a[0];
	sort(a,a+m*n);
	
	for(int i=m*n-1;i>=0;i--)
	{	t+=1;
		if(a[i]==p)add=t;
	}
	if(add%n!=0)
	{
		c=add/n+1;
		d=add-add/n*m;
		if(c%2==0){
			r=n-d+1;
		}
		else{
			r=d;
		}
	}
	if(add%n==0){
		c=add/n;
		d=0;
		if(c%2==0){
			r=1;
		}
		else{
			r=n;
		}
	}
	
	cout<<c<<" "<<r;
	return 0;
}
