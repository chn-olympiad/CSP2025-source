#include<bits/stdc++.h>
using namespace std;
long long n,a[1000009],bj[1000009],ans;
void dfs(long long k,long long ma,long long sum,long long gs,long long lea)
{
	if(k>n)
	{
		string ss="";
		if(gs>=3&&sum>ma*2)ans++;
		return ;
	}
	if(k>3)
	{
		string ss="";
		if(gs>=3&&sum>ma*2)ans++;
	}
	for(int i=lea;i<=n;i++)
	{
		if(bj[i]==1)continue;
		bj[i]=1;
		dfs(k+1,max(ma,a[i]),sum+a[i],gs+1,i+1);
		bj[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,0,0,0,1);
	cout<<ans;

	return 0;
}
