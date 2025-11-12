#include<bits/stdc++.h>
#define ll long long
#define N 6005
#define mod 998244353
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
ll n,m,k,jk,ans,sum,num,cnt,tot;
ll dis[N],vis[N],G[N][5],kis[N],wis[N];

void read(ll &x){
	x=0;ll ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){
		putchar('-');x=-x;
	}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));
}

ll ksm(ll x,ll y){
	ll z=1;while(y){
		if(y&1) z=z*x%mod;
		x=x*x%mod;y>>=1;
	}return z;
}

//void dfs(ll x,ll y){
//	
//}

ll C(ll x,ll y){
	if(x<0||x-y<0) return 0;
	return wis[x]*ksm(wis[x-y],mod-2)%mod*ksm(wis[y],mod-2)%mod;
}

void dfs(ll x,ll y,ll z){
	if(x>n){
		if(y*2<z) ans++;
		return;
	}
	dfs(x+1,dis[x],z+dis[x]);
	dfs(x+1,y,z);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);wis[0]=1;
	for(ll i=1;i<=5001;i++) wis[i]=wis[i-1]*i%mod;
	for(ll i=1;i<=n;i++) read(dis[i]),kis[dis[i]]++;
	sort(1+dis,1+dis+n);
	if(kis[1]==n){write(((ksm(2,n)-1ll-n-C(n,2ll))%mod+mod)%mod);return 0;}
	else if(n<=20){dfs(1,0,0);write(ans);return 0;}
	G[0][0]=1;
	for(ll j=1;j<=n;j++){
		for(ll i=5001;i>=dis[j];i--){
			G[i][1]+=G[i-dis[j]][0];
			G[i][2]+=G[i-dis[j]][1];
			G[i][2]+=G[i-dis[j]][2];
		}
	}
	for(ll i=1;i<=5001;i++) G[i][2]+=G[i-1][2];
	for(ll i=1;i<=n;i++) sum+=max(G[dis[i]][2],0ll);
	write(((((ksm(2ll,n)-C(n,2ll))%mod-n-1ll)%mod-sum)%mod+mod)%mod);
	return 0;
}/*

5
1 2 3 4 5

5
2 2 3 8 10

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
1042392
*/
