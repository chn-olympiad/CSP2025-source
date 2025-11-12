#include<bits/stdc++.h>
using namespace std;
long long int n,a[5001],u;
int pq(int x)
{
	long long int h[x+1]={0};
	h[1]=1;
	for(int i=2;i<=x;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			h[i]=(h[i]+h[j])%998244353;
		}
		h[i]++;
	}
	return h[x]%998244353;
}
int num(int x,int y)
{
	long long int z=0;
	if(x<=0||(x==1&&a[x]<=y))
	{
		return 0;
	}
	if(a[x]>=y)
	{
		z=z+pq(x-1)+1;
		z=z+num(x-1,y);
	}else{
		z=z+num(x-1,y-a[x]);
		z=z+num(x-1,y);
	}
	return z%998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int q=i;
		for(int j=i-1;j>=1;j--,q--)
		{
			if(a[q]<a[j])
			{
				int p;
				p=a[q];
				a[q]=a[j];
				a[j]=p;
			}
		}
	}
	for(int i=n;i>=3;i--)
	{
		u=(u+num(i-1,a[i]))%998244353;
	}
	cout<<u;
	return 0;
}