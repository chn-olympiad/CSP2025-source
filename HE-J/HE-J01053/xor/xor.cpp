#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int b[10000000];
int zhuan(int x)
{
	int s,y,c;
	for(int i=1;i<=x+1;i++)
	{
		y=x%2;
		a[i]=y;
		x=x/2;
		if(x<=1)
		{
			a[i+1]=x;
			c=i+1;
			break;
		}
	}
	int ans=0;
	for(int i=c;i>=1;i--)
	{
		ans=ans*10+a[i];
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		b[i]=zhuan(b[i]);
	}
	k=zhuan(k);
	int s=0;
	int ans;
	int max1=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int count=i;count<=j;count++)
			{
				s=(s|b[count]);
				if(s==k)
					ans=j-i+2; 
			}
			max1=max(max1,ans);
		}
	}
	cout<<ans;
	return 0;
}
