#include<bits/stdc++.h>
using namespace std;
int n,m,r,a=1,an,am,b;
int,main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=1,j;i<n*m;i++;
	{
		cin>>j;
		if(j>r) a++;
	}
	am=a/n+min(1,a%n);
	b=a%2n;
	if(b>n+1)
	{
		an=2n-b+1;
	}
	if(b=n||b=n+1)
	{
		an=n;
	}
	if(b<n)
	{
		an=b;
	}
	cout<<an<<" "<<am;
	fclose(stdin);
	fclose(stdout);
}
