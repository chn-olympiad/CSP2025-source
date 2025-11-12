#include<bits/stdc++.h>
using namespace std;
int a[50001],n,k;
int yi(int x,int y)
{
	string x1="",y1;
	int z1=a[x];
	for(int i=x+1;i<=y;i++)
	{
		x1="";
		while(z1)
		{
			x1+=char(z1%2+48);
			z1/=2;
		}
		int c=a[i];
		y1="";
		while(c)
		{
			y1+=char(c%2+48);
			c/=2;
		}
		int d=max(x1.size(),y1.size());
		int e=pow(2,d-1);
		while(y1.size()<d)y1+="0";
		while(x1.size()<d)x1+="0";
		for(int i=d-1;i>=0;i--)
		{
			if(x1[i]!=y1[i])
			z1+=e;
			e/=2;
		}
	}
	return z1;
}
bool huo(int l)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(yi(i,j)==k)
			{
				ans++;
				i=j+1;
			}
		}
	}
	return ans>=l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	int tou=1,wei=n,l;
	while(tou<=wei)
	{
		l=(tou+wei)/2;
		if(huo(l))tou=l+1;
		else wei=l-1;
	}
	cout<<wei<<endl;
	return 0;
}
