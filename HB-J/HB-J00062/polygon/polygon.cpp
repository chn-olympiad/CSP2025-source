#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n;
long long ans=0;
int a[N];
bool check(int sum,int maxn,int m)
{
	if(m>=3&&sum>2*maxn)
		return 1;
	return 0;
}
void dfs(int sum,int maxn,int m,int k,int f)
{
	if(f==1&&check(sum,maxn,m))
	{
		ans++;
	}
	if(k==n+1)
		return;
	dfs(sum+a[k],max(maxn,a[k]),m+1,k+1,1);
	dfs(sum,maxn,m,k+1,0);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,0,1,1);
	cout<<ans%998244353;
	return 0;
}
