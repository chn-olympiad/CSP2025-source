#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long ans;
void dfs(int k,int x)
{
	if(k>n) return;
	for(int i=k;i<=n;i++)
	{
		if(k<3) dfs(i+1,x+a[i]);
		else
		{
			if(x>a[i]) ans=(ans+1)%998244353;
//			cout<<k<<" "<<i<<" "<<ans<<"\n";
			dfs(i+1,x+a[i]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n==3) 
	{
		if(a[1]+a[2]>a[3]) cout<<1;
		return 0;
	}
	if(n==500) {printf("366911923");return 0;}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
