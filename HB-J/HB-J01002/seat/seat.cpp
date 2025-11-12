#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	
	int n,m,x,c,r;
	int a[101]={0};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i]<a[j])
				swap(a[i],a[j]);
		}
		if(a[i]==x)
			x=i;
	}
	c=(x-1)/n+1;
	r=x-(c-1)*n;
	cout<<c<<" "<<r;
}
