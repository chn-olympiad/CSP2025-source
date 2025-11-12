#include<bits/stdc++.h>
using namespace std;
bool px(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m,b=0;
	cin>>n>>m;
	int a[125]={0};
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,px);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			b=i;
		}
	}
	float c1=b/n;
	int c,r;
	if(int (c1)==c1+0)
	{
		c=c1;
	}
	else
	{
		c=c1+1;
	}
	if(c%2==0)
	{
		r=m-b%n;
	}
	else
	{
		r=b%n;
	}
	cout<<c<<' '<<r;
} 
