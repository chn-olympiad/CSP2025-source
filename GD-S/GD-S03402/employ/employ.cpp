#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[505][505][2],ans,a[505],b[505],prv[505],nxt[505];
void dfs(long long h,long long ma){
	if(n-m<ma)return;
	if(h>n){
		ans++,ans%=(998244353);
		return;
	}
	for(long long i=nxt[0];i<=n;i=nxt[i]){
		if(ma<b[i]&&!a[h]){
			prv[nxt[i]]=prv[i],nxt[prv[i]]=nxt[i];
			dfs(h+1,ma);
			prv[nxt[i]]=i,nxt[prv[i]]=i;
		}else{
			prv[nxt[i]]=prv[i],nxt[prv[i]]=nxt[i];
			dfs(h+1,ma+1);
			prv[nxt[i]]=i,nxt[prv[i]]=i;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m),nxt[0]=1,prv[n+1]=n;
	for(long long i=1;i<=n;i++){
		char c;
		cin>>c,a[i]=(c=='1'?0:1),nxt[i]=i+1,prv[i]=i-1;
	}
	for(long long i=1;i<=n;i++)scanf("%lld",&b[i]);
	sort(b+1,b+n+1);
	dfs(1LL,0LL),printf("%lld",ans);
	return 0;
}
