#include<bits/stdc++.h>
using namespace std;
int s[100];
int main()
{
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,c,r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>s[i];
	}
	int kk=s[0];
	sort(s+0,s+n*m);
	int a=0;
	while(s[a]!=kk)
	{
		a++;
	}
	a=n*m-a;
	c=a/n;
	double k=double(a)/double(n);
	if(k!=double(c))
	{
		c++;
	}
	if(c%2==0)
	{
		if(a%n==0)
		{
			r=1;
		}
		else{
			r=n-(a%n)+1;
		}
	}
	else
	{
		if(a%n==0)
		{
			r=n;
		}
		else
		{
			r=a%n;	
		}
	}
	cout<<c<<' '<<r; 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
