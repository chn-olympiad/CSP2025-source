#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;

ll n,a[5141],ans=0,b[5141];

bool vis[5141];

void dfs(int k,int kk,int l)
{
	if(kk==0){
		ll maxx=0,sum=0;
		for(int i=1;i<=k;i++) sum+=b[i],maxx=max(maxx,b[i]);
		if(sum>maxx*2) ans=(ans+1)%mod;
		return;
	}
	else{
		for(int i=l;i<=n;i++){
			if(vis[i]) continue;
			b[kk]=a[i];
			vis[i]=1;
			dfs(k,kk-1,i);
			vis[i]=0;
		}
		return;
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n<3){
		printf("0");
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]) printf("1");
		else printf("0");
	}
	else{
		for(int len=3;len<=n;len++){
			memset(vis,0,sizeof(vis));
			dfs(len,len,1);
		}
		printf("%lld",ans);
	}
	return 0;
}
