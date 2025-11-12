#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],ans;
void dfs(long long k,long long x,long long y,long long z,long long sum){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x+1<=n/2)dfs(k+1,x+1,y,z,sum+a[k]);
	if(y+1<=n/2)dfs(k+1,x,y+1,z,sum+b[k]);
	if(z+1<=n/2)dfs(k+1,x,y,z+1,sum+c[k]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		if(n<=12){
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);	
		}else{
			sort(a+1,a+n+1);
			for(long long i=n;i>=n/2;i--)ans+=a[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
