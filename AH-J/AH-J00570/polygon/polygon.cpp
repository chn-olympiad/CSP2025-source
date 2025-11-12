#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],l=0;
long long cnt=0;
void dfs(int k,long long m,int p,int q)
{
	if(m>n)
	{
		return ;
	}
	if(k>n)
	{
		l++;
		dfs(l,1,a[l+1],a[l+1]);
	}
	if(m<3)
	{
		dfs(k+1,m+1,p+a[k+1],a[k+1]);
		return ;
	}
	if(m>=3&&p<=2*q)
	{
		dfs(k+1,m+1,p+a[k+1],a[k+1]);
		return ;
	}
	cnt++;
	dfs(k+1,m,p+a[k+1]-a[k],a[k+1]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3)
	{
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
		{
			cnt++;
			cout<<cnt;
			return 0;
		}
	}
	dfs(1,1,a[1],a[1]);
	cout<<cnt%998244353;
	return 0;
}
