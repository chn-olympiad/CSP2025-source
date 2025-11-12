#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,a[5005],cnt;
void dfs(int step,int maxn,int sum,int gs)
{
	if (step>n)
	{
		if (gs>=3&&sum>2*maxn) cnt=(cnt+1)%MOD;
		return ;
	}
	dfs(step+1,max(maxn,a[step]),sum+a[step],gs+1);
	dfs(step+1,maxn,sum,gs);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    	cin>>a[i];
    if (n<=20)
    {
    	dfs(1,-1,0,0);
    	cout<<cnt;
	}
    else
    {
    	for (int i=3;i<=n;i++)
    	{
    		int tot=1;
    		for (int j=n-i+1;j<=n;j++)
    			tot=tot*j%MOD;
    		for (int j=2;j<=i;j++)
    			tot/=j;
    		cnt=(cnt+tot)%MOD;
		}
		cout<<cnt;
	}
    return 0;
}
