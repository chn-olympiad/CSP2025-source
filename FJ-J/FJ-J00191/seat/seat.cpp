#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,l=1,a1,n,m,s;
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<n*m;i++)
	{
		cin>>s;
		if(s>a1) l++;
	}
	if(l%n==0)
	{
		c=l/n;
		if(c%2==0) r=1;
		else r=n;
	}
	else
	{
		c=l/n+1;
		if(c%2==0) r=n-l%n+1;
		else r=l%n;
	}
	cout<<c<<" "<<r;
	fclose(stdin);fclose(stdout);
	return 0;
}