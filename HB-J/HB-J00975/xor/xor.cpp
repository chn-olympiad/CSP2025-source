#include <bits/stdc++.h>
using namespace std;
int yh(int a;int b)
{
	strig x=" ",y=" ";
	while(a)
	{
		x+=a%2;
		a/=2;
	}
	while(b)
	{
		y+=b%2;
		b/=2;
	}
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100001],l.s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			l=a[i]^a[i+1];
			for(int o=i+2;o<=j;o++)
			{
				l=l^a[o];
			}
			if(l==k)
			{
				s++;
			}
		}
	}
	cout<<s;
	return 0;
}
