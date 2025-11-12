#include<bits/stdc++.h>
using namespace std;
int a[5005],n,p;
void dfs(int t,int x,int y,int s)
{
	if(t==x)
	{
		if(s>y)
		{
			p++;
			p%=998244353;
		}
		return ;
	}
	dfs(t+1,x,y,s+a[t]);
	dfs(t+1,x,y,s);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=3;i<=n;i++)
	{
		p=0;
		int c=a[i]*2;
		dfs(1,i,c,a[i]);
		sum+=p;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
