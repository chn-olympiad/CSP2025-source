#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
int b[5005];
int polygonh(int x,int k,int num,int maxn)
{
	int f=0;
	if(k-1+x>n)return 0;
	if(x!=0)for(int i=k;i<=n;i++)
	{
		if(b[i]!=1)
		{
			if(a[i]>maxn)maxn=a[i];
			num+=a[i];
			b[i]=1;	
		}
		f+=polygonh(x-1,i+1,num,maxn)%998244353;
		num-=a[i];
		b[i]=0;
	}
	if(x==0)
	{
		if(num<=maxn*2)return 0;
		return 1;
	}
	return f%998244353;
}
long long yiyi(int x,int l)
{
	int f=0;
	if(l+x-1>n)return 0;
	if(x==0)return 1;
	for(int i=l;i<=n;i++)f+=yiyi(x-1,i+1);
	return f;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int num=0,y=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)y=0;
	}
	if(y==1)
	{
		for(int i=3;i<=n;i++)
		{
			num+=yiyi(i,1);
		}
		num-=1;
	}
	else for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)b[j]=0;
		int l=polygonh(i,1,0,0);
		num+=l; 
	}
	cout<<num;
}
