#include <bits/stdc++.h>
using namespace std;
int a[5001],ans=0,sum=0,n,maxx=-1;
bool v[5001];
void dfs(int t)
{
	if(t>=3)
	{
		if(sum>maxx*2) ans++;
	}
	if(t>=n) return ;
	for(int i=t;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			int k=maxx;
			maxx=max(maxx,a[i]);
			sum+=a[i];
			dfs(t++);
			maxx=k;
			sum-=a[i];
			v[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	ans%=998;
	ans%=353;
	ans%=244;
	cout<<(ans+1)/2;
	return 0;
}
