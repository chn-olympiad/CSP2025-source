#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,r=1,x=1;
int a[103];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			x++;
		}
	}
	if(x%n==0)
	{
		c=x/n;
	}
	else
	{
		c=x/n+1;	
	}
	if(c%2==0)
	{
		r=n-x%n+1;
	}
	else
	{
		if(x%n==0)
		{
			r=n;
		}
		else{
			r=x%n;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
