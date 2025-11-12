#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5e3+7;
int ans;
int n,a[N];
void dfs(int p,int d,int maxn,int s)
{
	if(p>n)return;
	if(s>=3&&d>2*maxn)
	{
		ans++;
	}
	for(int i=p+1;i<=n;i++)
	{
		dfs(i,d+a[i],max(maxn,a[i]),s+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)dfs(i,a[i],a[i],1);
	printf("%d",ans);
	return 0;
}
