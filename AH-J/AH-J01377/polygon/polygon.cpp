#include <bits/stdc++.h>
using namespace std;
int a[5010],b[5010],n;
long long sum,s;
void dfs(int dep,int m,int x)
{
	if(dep==m)
	{
		if(sum>2*b[m])s=(s+1)%998244353;
		return ;
	}
	for(int i=x;i<=n+dep+1-m;i++)
	{
		b[dep+1]=a[i];
		sum+=a[i];
		dfs(dep+1,m,i+1);
		b[dep+1]=0;
		sum-=a[i];
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		sum=0;
		dfs(0,i,1);
	}
	cout<<s;
	return 0;
}
