#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream cin("seat.in")
	ofstream cout("seat.out")
	int n,m,a,b,c,d,e,f;
	cin>>n>>m;
	int s[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>s[i];
	}
	a=s[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;i<n*m-1;j++)
		{
			if(s[j]>s[j+1])
			{
				c=s[j];
				s[j]=s[j+1];
				s[j+1]=c;
			}
		}
		
	}
	for(int i=0;i<n*m;i++)
	{
		if(s[i]==a)b=i;
	}
	c=b/n;
	if(b%n!=0)c+1;
	d=b%n;
	e=b-(c-1)*n;
	f=n-e;
	if(c%2!=0)cout<<c<<e;
	else cout<<c<<f;
	return 0;
}
