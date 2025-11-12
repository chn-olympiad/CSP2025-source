#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int t,n,a1[N],a2[N],a3[N],maxn=-1;
void dfs(int step,int sum,int ca,int cb,int cc)
{
	if (ca>n/2||cb>n/2||cc>n/2) return ;
	if (step>n)
	{
		maxn=max(maxn,sum);
		return ;
	}
	dfs(step+1,sum+a1[step],ca+1,cb,cc);
	dfs(step+1,sum+a2[step],ca,cb+1,cc);
	dfs(step+1,sum+a3[step],ca,cb,cc+1);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		maxn=-1;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		if (n<=10)
		{
			dfs(1,0,0,0,0);
			cout<<maxn<<endl;
		}
		else
		{
			sort(a1+1,a1+n+1,greater<int>());
			int tot=0;
			for (int i=1;i<=n/2;i++)
				tot+=a1[i];
			cout<<tot<<endl;
		}
	}
	return 0;
}
