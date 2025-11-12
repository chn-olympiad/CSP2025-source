#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],ans,k;
const long long mo=998244353;
void dfs(long long num,long long h,long long sum,long long mx)
{
	if(num==k&&sum>mx*2)
	{
		ans=(ans+1)%mo;
		return ;
	}
	if(h>n)return ;
	long long mx_2=max(mx,a[h]);
	dfs(num+1,h+1,sum+a[h],mx_2);
	dfs(num,h+1,sum,mx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(k=3;k<=n;k++)dfs(0,1,0,0);
	cout<<ans;
	return 0;
}
