#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m,n,d,c=1,r=1,y,p=1;
	cin>>m>>n;
	for(int l=1;l<=m*n;l++)
	{
		cin>>d;
		if(l==1)
		{
			y=l;
		}
		do
		{
			p++;
		}while(y<d);
	}
	if(p<n)
	{
		cout<<c<<p;
	}
		return 0;
	for(int z=1;z<=m*n;z++)
	{
		if(p>n)
		{
			c++;
			p-=n;
		}
		if(p<n&&c%2==1)
		{
			r=p;
			cout<<c<<r<<endl;
			return 0;
		}
		if(p<n&&c%2==0)
		{
			r=n-p;
			cout<<c<<r<<endl;
			return 0;
		}
	}
	return 0;
}
