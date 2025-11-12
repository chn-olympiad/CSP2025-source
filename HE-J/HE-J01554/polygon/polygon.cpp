#include<bits/stdc++.h>
#define int long long
using namespace std;
const int t=998244353;
int n,a[500100],j[500100],ans,ma=-1;
void dfs(int k,int m,int num)
{
	if(k>n) return;
	if(m>=3&&num>2*a[k]) ans=(ans+1)%t;
	for(int i=k+1;i<=n;i++)
		dfs(i,m+1,num+a[i]);
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(ma==1)
	{
		int k=1,y;
		for(int i=1;i<=n;i++)
		{
			k=(k*i)%t;
			a[i]=k;
		}
		a[0]=1;
		for(int i=3;i<=n;i++)
		{
			y=a[n]/a[i];
			y=y/a[n-i];
			ans=(ans+y)%t;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		dfs(i,1,a[i]);
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
