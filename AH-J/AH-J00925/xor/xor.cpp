#include<bits/stdc++.h>
using namespace std;
long long int a,b,c;
long long int k;
long long int x[1001000],dp[1001000];
int m[1000000],n[1000000],p,q=0;
int d=0;
int yihuo(int z,int w)
{
	p=0;
	q=0;
	while(z>0)
	{
		m[p]=z%2;
		z=z/2;
		p=p+1;
	}
	while(w>0)
	{
		n[q]=w%2;
		w=w/2;
		q=q+1;
	}
	b=max(p,q);
	if(p>q)
	{
		for(int i=q;i<=p;i++)
		{
			n[i]=0;
		}
	}
	else
	{
		for(int i=p;i<=q;i++)
		{
			m[i]=0;
		}
	}
	for(int i=0;i<b;i++)
	{
			if(m[i]==n[i])
			{
				m[i]=0;
			}
			else
			{
				m[i]=1;
			}
	}
	c=0;
	for(int i=0;i<b;i++)
	{
		if(m[i]==1)
		{
			c=c+pow(2,i);
		}
		
	}
	for(int i=0;i<=b+10;i++)
	{
		m[i]=0;
		n[i]=0;
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>k;
	for(int i=1;i<=a;i++)
	{
		cin>>x[i];
		dp[i]=x[i];
		if(x[i]==k)
		{
			d=1;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			dp[j]=yihuo(dp[j-1],dp[j]);
			if(dp[j]==k&&j-i>d)
			{
				d=j-i;
			}
		}
		for(int j=1;j<=a;j++)
		{
			dp[j]=x[j];
		}
	}
	cout<<d;
	return 0;
}
