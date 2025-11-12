#include<bits/stdc++.h>
using namespace std;
int n,a[5010],m,num,ans=0;
bool g=1;
int mo=998244353;
void dfs(int k,int x)
{
	if(k==0)
	{
		if(num>m*2) ans=(ans+1)%mo;
		return ;
	}
	if(x==0) return ;
	int y=m,z=num;
	for(int i=x;i>=1;i--)
	{
		m=max(m,a[i]);
		num+=a[i];
		dfs(k-1,i-1);
		m=y;
		num=z;
	}
}
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	g=1;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) g=0;
	}
	if(g)
	{
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				ans=(ans+j*(n-j+1) )%mo;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			m=a[j];
			num=a[j];
			dfs(i-1,j-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
