#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,maxx;
int s[88888],a[99999];
void dfs(int x,int ans,int q)
{
	if(x>n)
	{
		if(ans>a[maxx]*2)
		sum++;
		return ;
	}
	maxx=x;
	dfs(x+1,ans+a[x],maxx);
	maxx=q;
	dfs(x+1,ans,q);
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		for(int i=1;i<=n-2;i++)
			sum=sum*i%998244353;
		cout<<sum;
		return 0;
	}
	else
	dfs(1,0,1);
	cout<<sum;
	return 0;
}