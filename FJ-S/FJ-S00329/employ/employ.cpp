#include<bits/stdc++.h>
using namespace std;
const int N=1000,Mod=998244353;
long long ans;
int a[N];
bool book[N];
int n,m;
string A;
int w[N];
void dfs(int x)
{
	if(x==n+1)
	{
		int no_pass=0;
		for(int W=1;W<=n;W++)
		{
			int i=a[W];
			if(A[W-1]=='0')
			{
				no_pass++;
				continue;
			}
			if(no_pass>=w[i])
			{
				no_pass++;
				continue;
			}
		}
		if(n-no_pass>=m)
		{
			
			ans++;
			ans%=Mod;
		}
		
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!book[i])
		{
			book[i]=1;
			a[x]=i;
			dfs(x+1);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>A;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}