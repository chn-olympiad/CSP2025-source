#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int MOD=99844353;
int num[N];
int vid[N];
int ans=0;
int n;
int maxx=0;
void dfs(int mmax,int summ,int q,int p)
{
	if(q>2)
	{
		if(summ>2*mmax)
		{
			ans++;
			ans%=MOD;
		}
	}
	for(int i=p+1;i<=n;i++)
	{
		if(vid[i]==0)
		{
			vid[i]=1;
			dfs(max(mmax,num[i]),summ+num[i],q+1,i);
			vid[i]=0;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		maxx=max(maxx,num[i]);
	}
	dfs(0,0,0,0);
	cout<<ans%MOD;
	return 0;
} 