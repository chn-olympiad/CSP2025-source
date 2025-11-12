#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[100];
int main()
{
	int n,m,x;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=a[1];
	}
	
	sort(a+1,a+1+b,cmp);
	for(int i=1;i<=b;i++)
	{
		if(a[i]==x)
		{
			if(i<=n)
			{
				cout<<1<<i;
			}
			int r=i%n;
			int c=(i+r)/n;
			if(c%2!=0)
			{
				cout<<c<<" "<<r;
				break;
			}
			else {
			cout<<c<<" "<<n+1-r;
		}
		}
	}
	return 0;
}
