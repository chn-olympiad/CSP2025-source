#include<bits/stdc++.h>
using namespace std;
int n,a[6000];
long long ans;
void dfs(int i,int t,int maxx,int sum)
{
	if(i>n)return;
	for(int j=t;j<=n;j++)
	{
		int maxxx=max(maxx,a[j]);
		int summ=sum+a[j];
		if(i>=3&&summ>2*maxxx)
		{
			ans+=(1<<(n-j))%998244353;
			ans%=998244353;
		}
		else dfs(i+1,j+1,maxxx,summ);
	}
	return;
}
bool comp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,comp);
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
}