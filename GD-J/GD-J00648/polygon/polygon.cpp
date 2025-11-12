#include<bits/stdc++.h>
using namespace std;
int a[5003],k,n,ans;
const int mod=998244353;
//int cnt;
bool pd[5003];
inline bool check()
{
//	cnt++;
	int maxn=-1;
	int sum=0;
	for(int i=1; i<=n; i++)
		if(pd[i])
		{
			maxn=max(maxn,a[i]),sum+=a[i];
		}
		return sum>maxn*2;
}
void dfs(int top,int m)
{
	if(top>k)
	{
		if(check())
		{
			ans++;
			if(ans==mod)
				ans=0;
			return ;
		}
		return;
	}
	else
		for(int i=m+1; i<=n; i++)
		{
			if(pd[i])
				continue;
			pd[i]=true;
			dfs(top+1,i);
			pd[i]=false;
		}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=3; i<=n; i++)
	{
		fill(pd,pd+n+1,false);
		k=i;
		dfs(1,0);
	}
	cout<<ans;
//	cout<<'\n'<<cnt;
//	cout<<0;
	return 0;
}
