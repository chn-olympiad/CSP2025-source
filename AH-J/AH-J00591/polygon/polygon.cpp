#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;
void dfs(long long mx,long long sum,long long sum2,long long id)
{
	if(sum>mx*2 && sum2>2) ans++;
	for(long long i=id+1; i<=n; i++) dfs(max(mx,a[i]),sum+a[i],sum2+1,i);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}