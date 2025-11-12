#include <bits/stdc++.h>
using namespace std;
int num=0;
int n,k,a;
long long s[500001];
int er_jin(int x)
{
    int  g[500001],i=0,y=0;
    while (x!=0)
    {
    	g[i]=x%2;
    	x/=2;
    	i++;
	}
	i-=1;
	while (g[i]==0) i--;
	for (int j=i;j>=0;j--)
	{
		y*=10;
		y+=g[i];
	}
	return y;
}
int xor_k(long long a,long long b)
{
	int g=0,i=0;
	while (a!=0 && b!=0)
	{
		if (a%10!=b%10)
		{
			g+=pow(2,i);
		}
		i++;
		a/=10;
		b/=10;
	}
	if (a!=0)
	{
		while (a!=0)
		{
			g+=pow(2,i);
			i++;
		}
	}
	if (b!=0)
	{
		while (b!=0)
		{
			g+=pow(2,i);
			i++;
		}
	}
	return g;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
    	cin>>a;
    	if (a==k) num++;
    	s[i]=er_jin(a);
	}
	for (int i=1;i<=n;i++)
	{
		if (i+1<=n && xor_k(s[i],s[i+1])==k)
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}

