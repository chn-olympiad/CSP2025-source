#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;

int n,a[5005],f[5005][5],ans=0,maxnn=0;

void dfs(int x,int maxn,int sum)
{
	if(x==n+1)
	{
		if(sum>2*maxn)
			++ans;
		return;
	}
	dfs(x+1,max(maxn,a[x]),sum+a[x]);
	dfs(x+1,maxn,sum);
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	  cin>>a[i];
	  maxnn=max(maxnn,a[i]);
    }
    if(maxnn==1)
    {
      cout<<((1<<n-n*(n-1))/2%M-1-n)<<"\n";
      return 0;
	}
	dfs(1,0,0);
	cout<<ans<<"\n";
	return 0;
}
