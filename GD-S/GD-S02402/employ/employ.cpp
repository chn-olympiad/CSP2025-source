#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=19;
inline ll read(){
	ll x=0;char f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0',c=getchar();}
	return f?x:-x;
}
int n,m,c[N];
char st[N];
ll dp[N][1<<N][N];
inline void upd(ll&x,ll y){
	if((x=x+y)>=mod)x-=mod;
}
int pop[1<<N];
inline int lowbit(int x){
	return x&-x;
}
int solve(){
	n=read(),m=read();
	scanf("%s",st+1);
	for(int i=0;i<n;++i)c[i]=read();
	dp[0][0][0]=1;
	int mx=(1<<n);
	for(int i=1;i<mx;++i){
		if(i==lowbit(i))pop[i]=1;
		else pop[i]=pop[i&(i-1)]+1;
	}
	for(int i=0;i<n;++i){
		for(int s=0;s<mx;++s){
			if(pop[s]==i){
				for(int k=0;k<=i;++k){
					if(dp[i][s][k]){
						for(int j=0;j<n;++j){
							if(!((s>>j)&1)){
								upd(dp[i+1][s|(1<<j)][k+((i-k<c[j])&&(st[i+1]=='1'))],dp[i][s][k]);
							}
						}
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=m;i<=n;++i){
		upd(ans,dp[n][mx-1][i]);
	}
	printf("%lld",ans);
	return 0;
}
/*
3 2
101
1 1 2

2
*/
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	while(T--){
		solve();
		if(T!=0)printf("\n");
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
