#include <bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n;
int a[5005];
long long f=0;
vector<int> ans;
bool pd=true;
void dfs(int dep,int sum)
{
	if(dep>n) 
	{
		if(ans.size()<3) return;
		vector<int> p=ans;
		sort(p.begin(),p.end(),greater<int>());
		if(sum>p[0]*2) 
			f++;
		return;
	}
	ans.push_back(a[dep]);
	dfs(dep+1,sum+a[dep]);
	ans.pop_back();
	dfs(dep+1,sum);
}
void solve1()
{
	ans.clear();
	f=0;
	dfs(1,0);
	cout<<f<<endl;
}
void solve2()
{
	long long ans1=1;
	for(int i=1;i<=n;i++)
	{
		ans1*=2;
		ans1%=mod;
	}
	ans1-=(n%mod);
	ans1-=((n*(n-1)/2)%mod);
	ans1--;
	if(ans1<0)
	{
		while(ans1<0)
			ans1+=mod;
	}
	cout<<ans1%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) pd=false;
	}
	if(pd==true)
	{
		solve2();
		return 0;
	}
	solve1();
	return 0;
}
