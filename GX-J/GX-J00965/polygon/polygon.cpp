#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5005],cnt;
bool f[5005];
void dfs(int s,long long ma,int x,long long num)
{
	if(x>s)
	{
		if(ma*2<num)
			cnt++;
		cnt%=MOD;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			dfs(s,max(ma,a[i]),x+1,num+a[i]);
			f[i]=0;
		}
	}
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		dfs(i,0,1,0);
	}
	cout<<cnt;
	return 0;
}
