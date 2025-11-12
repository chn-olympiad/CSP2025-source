#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ax[100],ay=1,bx[100],by=1,cx[100],cy=1;
int sum;

int yh(int a,int b)
{
	int d=0;
	while(a>=1)
	{
		ax[ay]=a%2;
		ay++;
		a/=2;
	}
	while(b>=1)
	{
		bx[by]=b%2;
		by++;
		b/=2;
		
	}
	cy=max(ay,by);
	for(int i=1;i<=cy;i++)
	{
		if(ax[i] != bx[i])
		{
			cx[i]=1;
			
		}
		else
		{
			cx[i]=0;
		}
	}
	for(int i=1;i<=cy;i++)
	{
		
		if(cx[i]==1) d += pow(2,i-1);
	}
	return d;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) sum++;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(yh(a[i],a[j]) == k) sum++;
		}
	}
	for(int i=1;i<=n-2;i++)
	{
		if((yh(yh(a[i],a[i+1]),a[i+2])) == k) sum++;
	}
	cout<<sum;
	return 0;
}
