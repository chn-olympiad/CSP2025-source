#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l[5005],vis[5002],f,maxn;
ll ans;
ll mod(ll a,ll b){
	return (a+b)%b;
}
void dfs(int dep,ll cnt,ll maxn){
	if(dep>n) return;
	for(int i=dep-1;i<n;i++){
		if(vis[i])continue;
		ll old = maxn;
		vis[i]=1;
		cnt+=l[i];
		maxn=max(maxn,l[i]*2);
		if(dep>=3 && cnt>maxn) {
			ans++; 
		}else if(dep>=3){
			cnt-=l[i];
			maxn = old;
			dep--;
		}
		dfs(dep+1,cnt,maxn);
		vis[i]=0;
		cnt-=l[i];
		maxn = old;
	}
}
int main(){
	freopen("polygon.in","r",stdin);	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld",&l[i]);
		if(f==0&&l[i]!=1)f=1;
		maxn = max(maxn,l[i]);
	}
	if(!f){
		for(int i=3;i<=n;i++){
			ll a=1,b=1;
			for(int j=2;j<=i;j++) a*=j;
			for(int j=n,k=1;k<=i;j--,k++) b*=j;
			ans += b/a;
		}
		printf("%lld",mod(ans,998244353));
		return 0;
	}else if(n<=3){
		if(l[0]+l[1]+l[2]>2*maxn){
			printf("1");
		}else{
			printf("0");
		}
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",mod(ans,998244353));
	return 0;
}
