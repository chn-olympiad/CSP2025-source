#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int ha(int x)
{
	int cnt=0;
	while(x!=0)
	{
		x/=10;
		cnt++;
	}
	return cnt;
}
int zhu(int x)
{
	int a[25];
	int cnt=0;
	for(int i=1;;i++)
	{
		if(x<=0) break;
		int k=x%2;
		a[i]=k;
		x/=2;
		cnt++;		
	}
	int z=0;
	for(int i=cnt;i>=1;i--)
	{
		z+=pow(10,i-1)*a[i];		
	}	
	return z;
}
int f(int x,int y)
{
	int a=ha(x);
	int b=ha(y);
	int len=max(a,b);
	int z=0; 
	for(int i=len-1;i>=0;i--)
	{
		int w=
		int e=
		if(w!=e)
		{
			z+=pow(10,i);	
		}		
	}
	return z;
}
int uhz(int x)
{
	int len=ha(x);
	int z=0;
	for(int i=len-1;i>=0;i--)
	{
		z+=pow(10,i)*x[i];		
	}
	return z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,o;
	cin>>n>>o;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i]=zhu(x);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int m=0;
			for(int k=i;k<=j;k++)
			{
				m=f(m,k);						
			}
			if(uhz(m)==o)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
