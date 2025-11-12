#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define maxn 1000005
#define mod 998244353
using namespace std;
int a[maxn],ans=0,n,p[maxn];
int calc()
{
	int ax=-1e18,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i])
		{
			ax=max(a[i],ax);
			sum+=a[i];
		}
	}
	if(sum>2*ax)return 1;
	else return 0; 
}
void dfs(int dep,int siz,int lst)
{
	if((dep>siz)&&calc())
	{
		ans++;
		ans%=mod;
		return;
	}
	for(int i=lst+1;i<=n;i++)
	{
		p[i]=1;
		dfs(dep+1,siz,i);
		p[i]=0;
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)dfs(0,i,0);
	cout<<ans;
	return 0;
}