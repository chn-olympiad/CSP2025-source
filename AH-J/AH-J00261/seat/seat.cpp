#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a[2000],k,pm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k) pm=n*m-i+1;
	}
	c=(pm-1)/n+1;
	if(c%2==0) r=n-(pm-1)%n;
	if(c%2==1) r=(pm-1)%n+1;
	cout<<c<<" "<<r;
	return 0;
}
