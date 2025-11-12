#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans=0;
void dfs(int now,long long sum,int m_ax,int choose)
{
	if(now>n)
	{
		if(sum>m_ax*2 && choose>=3)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(now+1,sum+a[now],max(m_ax,a[now]),choose+1);
	dfs(now+1,sum,m_ax,choose);
}
int main ()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	dfs(1,0,-1,0);
	cout<<ans;
    return 0;
}