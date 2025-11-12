#include<iostream>
using namespace std;
int n,k;
int m[500005]={};
int as[25]={},bs[25]={},s[25]={},rs=0,exs=0;
int d[25]={0,1,2,4,8,16,32,64,128,256,512,1024};
int p(int a,int b)
{
	if(a==b)
	{
		return a;
	}
	rs=0;
	for(int i=20;i>=1;i--)
	{
		as[i]=0;
		bs[i]=0;
		s[i]=0;
		if(a>=d[i])
		{
			as[i]=1;
			a-=d[i];
		}
		if(b>=d[i])
		{
			bs[i]=1;
			b-=d[i];
		}
		if(bs[i]!=as[i])
		{
			s[i]=1;
		}
	}
	for(int i=1;i<=20;i++)
	{
		rs=rs+(s[i]*d[i]);
	}
	return rs;
}
int zp(int x,int y)
{
	int yu=0;
	if(y-x>1)
	{
		yu=p(m[x],m[x+1]);
		for(int q=x+2;q<=y;q++)
		{
			yu=p(yu,m[q]);
		}
		return yu;
	}
	else
	{
		return p(m[x],m[y]);
	}
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	for(int i=11;i<=20;i++)
	{
		d[i]=2*d[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(zp(i,j)==k)
			{
				exs++;//cout<<i<<' '<<j<<endl;
				i=j+1;
				
			}
		}
	}
	cout<<exs;
	return 0;
}
