#include<bits/stdc++.h>
using namespace std;
int read()
{
	int tmp=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+c-'0';
		c=getchar();
	}
	return tmp*f;
}
int n,m;
int a[10001];
bool cmp(int u,int v)
{
	return u>v;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)
	{
		a[i]=read();
	}
	int tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==tmp)
		{
			tmp=i;
			break;
		}
	}
	int tmp2=tmp/n+(tmp%n!=0);
	int tmp3;
	if(tmp%n==0)
	{
		tmp3=n;
	}
	else
	{
		tmp3=tmp%n;
	}
	if(tmp2%2==0)
	{
		cout<<tmp2<<" "<<n-tmp3+1;
	}
	else
	{
		cout<<tmp2<<" "<<tmp3;
	}
	return 0;
}
