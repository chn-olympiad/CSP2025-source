#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int a[5010];
int n;
int cnt=0;
bool st[5010];
void dfs(int x,int sum,int ma) 
{
	if(x==n+1)
	{
		if(sum>ma*2)
		{
			cnt++;
			cnt%=998244353;
		}
		return ;
	}
	for(int i=x;i<=n;i++)
	{
		int summ=sum,maa=ma;
		if(st[i]==1) continue;
		st[i]=1;
		maa=max(maa,a[x]);
		summ+=a[x];
		dfs(i+1,summ,maa);
		st[i]=0;
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,0,i);
	}
	cout<<cnt%998244353;
	return 0;
}
