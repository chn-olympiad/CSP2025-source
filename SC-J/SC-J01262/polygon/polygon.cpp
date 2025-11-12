#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ptc putchar
using namespace std;
const int N=5008;
const int mod=998244353;
int n;
int a[N];
int maxna;
int ans;
void dfs(int now,int maxn,int sum,int cnt){
	if(now==n+1){
		if(cnt>=3&&sum>maxn*2){
			++ans;
			ans%=mod;
		}
		return;
	}
	dfs(now+1,max(maxn,a[now]),sum+a[now],cnt+1);
	dfs(now+1,maxn,sum,cnt);
	return;
}
ll qpow(int a,int b){
	int t=1;
	ll c=a,r=1;
	while(t<=b){
		if(t&b){
			r*=c;
			r%=mod;
		}
		c*=c;
		c%=mod;
		t<<=1;
	}
	return r;
}
int inv(int n){
	return qpow(n,mod-2);
}
ll c(int n,int m){
	ll r=1;
	for(int i=n;i>=n-m+1;i--){
		r*=i;
		r%=mod;
	}
	for(int i=1;i<=m;i++){
		r*=inv(i);
		r%=mod;
	}
	return r;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		maxna=max(maxna,a[i]);
	}
	if(maxna==1){
		printf("%lld\n",((qpow(2,n)-1-c(n,1)-c(n,2))%mod+mod)%mod);
		return 0;
	}
	else{
		dfs(1,0,0,0);
		printf("%d\n",ans);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}