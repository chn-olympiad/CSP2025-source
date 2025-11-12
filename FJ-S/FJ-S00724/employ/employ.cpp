#include<bits/stdc++.h>
using namespace std;
int n,m;
int s;
int a[505];
int b[505];
bool c[505];
void fun(int k)
{
	if(k==n+1)
		return;
	for(int i=1;i<=n;i++)
	{
		b[k]=i;
		c[i]=1;
		s=(s+1)%998244353;
		fun(k+1);
		c[i]=0;
	}
}
int fun1()
{
	fun(1);
	if(m==1)
		return s;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==1)
	{
		long long h=1;
		for(int i=1;i<=n;i++)
		{
			h=(h*i)%998244353;
		}
		printf("%d",h);
		return 0;
	}
	//printf("%d",fun1());
	return 0;
}
