#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,mod=998244353;
int n,a[maxn],ans;
bool cmp(int pre,int nxt)
{
	return pre>nxt;
}
void dfs(int h,int sum,int mx)
{
	if(h>n)
	{
		if(sum>mx*2)
		{
			ans%=mod;
			ans++;	
		}
		return;
	}
	dfs(h+1,sum+a[h],max(mx,a[h]));
	dfs(h+1,sum,mx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
