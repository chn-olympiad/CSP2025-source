#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005];
int b[5005];
bool f[5005];
int n,ans=0;
void dfs(int dep,int k)
{
	if(dep>k)
	{
		int cnt=0;
		for(int i=1;i<=k;i++)
			cnt+=b[i];
		if(cnt>b[k]*2) ans=(ans+1)%MOD;
		return;
	}
	for(int i=dep;i<=n;i++)
	{
		if(!f[i]&&a[i]>=b[dep-1])
		{
			b[dep]=a[i];
			f[i]=true;
			dfs(dep+1,k);
			b[dep]=0;
			f[i]=false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	bool pd=false;
	for(int i=1;i<=n;i++)
		if(a[i]!=1)
		{
			pd=true;
			break;
		}
	if(!pd)
	{
		for(int i=n-2,j=1;i>=1&&j<=n-2;i--,j++)
			ans=ans+i*j;
		cout<<ans<<endl;
		return 0;
	}
	
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(1,i);
	}
	cout<<ans<<endl;
	return 0;
}
