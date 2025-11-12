#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int yihuo(int q,int w)
{
	long long o1=0;
	long long o2=0;
	int l=0;
	while(q>=1)
	{
		if(q%2==0)
		{
			o1*=10;
		}
		else
		{
			o1*=10;
			o1+=1;
		}
		l++;
	}
	long long o3=0;
	long long o4=0;
	for(int i=1;i<=l;i++)
	{
		o3=o1%10;
		o1/=10;
	}
	int u=0;
	while(w>=1)
	{
		if(w%2==0)
		{
			o2*=10;
		}
		else
		{
			o2*=10;
			o2+=1;
		}
		u++;
	}
	for(int i=1;i<=u;i++)
	{
		o4=o2%10;
		o2/=10;
	}
	int maxx=max(l,u);
	long long jie=0;
	for(int i=1;i<=maxx;i++)
	{
		if(o3%10!=o4%10)
		{
			jie*=10;
			jie+=1;
		}
		else
		{
			jie*=10;
		}
	}
	long long jie2=1;
	int ans=0;
	while(ans==maxx)
	{
		jie2*=10;
		if(jie%10==1)
		{
			jie2+=2^ans-1;
		}
	}
	return jie2;
}
int sou(int x,int y)
{
	if(x==y)
	{
		return a[x];
	}
	else
	{
		int dangqian;
		for(int i=x;i<=y-1;i++)
		{
			if(i==x)
			{
				yihuo(i,i+1);
				dangqian=yihuo(i,i+1);
			}
			else if(i==y-1)
			{
				return yihuo(dangqian,i+1);
			}
			else
			{
				dangqian=yihuo(dangqian,i+1);
			}
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sou(i,j)==k)
			{
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
