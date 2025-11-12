#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];	
	}
	int g=a[0],s,d;
	sort(a+0,a+m*n,cmp);
	for(int i=0;i<m*n;i++)
	{
		if(a[i]==g)
		{
			s=i;
			d=i;
		}
	} 
	s=s/n+1;
	d=d%m+1;
	cout<<s<<" ";
	if(s%2==1)
	{
		cout<<d;
	}
	else
	{
		sort(a+(s-1)*n,a+s*n);
		for(int i=(s-1)*n;i<s*n;i++)
		{
			if(a[i]==g)
			{
				cout<<i%m+1;
			}
		}
	}
	return 0;
}
