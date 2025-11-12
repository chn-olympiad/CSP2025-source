//普巴保佑我AC
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int d[500005];
int q[500005];
inline int dfs(int s,int f)
{
	if(s==n+1)
		return f;
	int ans=INT_MIN;
	for(int i=s;i<=n;++i)
	{
		if((q[i]^q[s-1])==k)
			ans=max(ans,dfs(i+1,f+1));
		else
			ans=max(ans,dfs(i+1,f));
	}
	return ans;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>d[i];
		q[i]=(q[i-1]^d[i]);
	}
	cout<<dfs(1,0);
	return 0;
}