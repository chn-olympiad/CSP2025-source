#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool p[1005]; 
int n,a[10005],l;
bool f=1;
void ok(int x)
{
	if(x==n+1)
	{
		int t=0,s=0,maxa=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]==1)
			{
				t++;
				s+=a[i];
				maxa=max(maxa,a[i]); 
			}
		}
		if(s>maxa*2 && t>=3) l=(l+1)%mod;
		return ;
	}
	p[x]=1;
	ok(x+1);
	p[x]=0;
	ok(x+1);
}
int C(int n,int m)
{
	int s=1;
	for(int i=n;i>=n-m+1;i--)
	{
		s=(s*i)%mod;
	}
	for(int i=1;i<=m;i++)
	{
		s/=i;
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f==1)
	{
		int s=0;
		for(int i=3;i<=n;i++)
		{
			s=(s+C(n,i))%mod;
		}
		cout<<s;
		return 0;
	}
	ok(1);
	cout<<l;
	return 0;
}

