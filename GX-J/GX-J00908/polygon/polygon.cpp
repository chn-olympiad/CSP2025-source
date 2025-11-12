#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
long long ans,n,a[501];
void dfs(long long f,long long k,long long t,long long s)
{
	if(t==f) {ans++;ans%=998244353;return;}
	if(f-t>(n-k+1)) return;
	if(t==f-1&&a[k]>=s) return;
	dfs(f,k+1,t+1,s+a[k]);
	dfs(f,k+1,t,s);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		dfs(i,1,0,0);
	cout<<ans;
	return 0;
}
