#include<bits/stdc++.h>
using namespace std;
const int mod=998224353;
const int maxn=5e3+10;
int a[maxn];
int n;
long long ans=0;
void dfs(int i,int num)
{
	if(i>n) return;
	for(int j=i;j<=n;++j)
	{
		if(num>a[j])
		{
			++ans;
			ans%=mod;
		}
		dfs(j+1,num+a[j]);
	}
}
int main()
{
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}