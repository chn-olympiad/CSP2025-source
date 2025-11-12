#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5010],b[5010],t;
bool vis[5010];
void dfs(ll y,ll x,ll ma,ll s,ll u){
	if(x==y&&s>ma*2){
		t=(t+1)%mod;
		return;
	}
	for(int i=u;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[x]=i;
			dfs(y,x+1,max(ma,a[i]),s+a[i],i+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1)t++;
	}
	if(t==n){
		t=1;
		for(int i=1;i<=n;i++)
		t=t*2%mod;
		printf("%lld",(t-1-n-n*(n-1)/2+mod)%mod);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	t=0;
	for(int i=3;i<=n;i++)
	dfs(i,0,0,0,1);
	printf("%lld",t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
