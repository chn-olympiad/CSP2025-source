#include<iostream>
#include<cstdio>
using namespace std;
int ans=1;
long long num=1;
void jiecheng(int k,int n)
{
	if(k==n+1)
	{
		ans=0;
		return;
	}
	if(ans==0)
	{
		return;
	}
	else
	{
		num=num*k%998244353;
		jiecheng(k+1,n);
	}
} 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	int n,m;
	long long ans;
	cin>>n>>m;
	int a,b[501];
	for(int i=1;i<=n;i++)
	{
		cin>>a;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			n--;
		}
	}
	jiecheng(1,n);
	cout<<num;
} 
