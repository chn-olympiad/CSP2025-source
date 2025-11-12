#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans[5010],cnt,maxn,sum;
void dfs(int len,int x,int pos)
{
	if(len==x+1)
	{
		cnt=maxn=0;
		for(int i=1;i<=x;i++)
		{
			cnt+=ans[i];
			maxn=max(maxn,ans[i]);
		}
		if(cnt>(maxn*2))
			sum++;
		return ;
	}
	for(int i=pos+1;i+x-len<=n;i++)
	{
		ans[len]=a[i];
		dfs(len+1,x,i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3)
	{
		cout<<0<<'\n';
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		dfs(1,i,0);
	}
	cout<<sum<<'\n';
	return 0;
}
