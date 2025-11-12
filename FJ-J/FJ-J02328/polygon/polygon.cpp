#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int n,l[N],f[N];
long long ans;
void dfs(int x,int k,int mx,int a,int u)
{
	if(k==x)
	{
		if(a>(2*mx))
		{
			f[x]=(f[x]+1)%mod;
		}
		return ;
	}
	int l1=mx;
	for(int i=u+1;i<=n;i++)
	{
		mx=max(mx,l[i]);
		a+=l[i];
		dfs(x,k+1,mx,a,i);
		a-=l[i];
		mx=l1;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=3;i<=n;i++)
	{
		dfs(i,0,-1,0,0);
	}
	for(int i=3;i<=n;i++)
	{
		ans+=f[i];
	}
	cout<<ans<<endl;
	return 0;
}
