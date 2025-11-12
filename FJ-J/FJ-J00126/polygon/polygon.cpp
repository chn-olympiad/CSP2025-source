#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+50;
const ll mod=998244353;
ll n,a[N],ans,dp[N],fac[N];
bool fg=1;
vector<ll>g;
set<vector<ll> >st;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48),ch=getchar();}
	return x*f;
}
void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x<10){putchar(x+48);}
	else{write(x/10);putchar(x%10+48);}
	return;
}
//O(n!)
void dfs(ll k){
	if(g.size()>=3){
		ll maxn=0,sum=0;
		for(ll i=0;i<(ll)(g.size());i++){
			sum+=a[g[i]];
			maxn=max(maxn,a[g[i]]);
		}
		if(sum>2*maxn)st.insert(g);
	}
	for(ll i=k+1;i<=n;i++){
		g.push_back(i);
		dfs(i);
		g.pop_back();
		dfs(i);
	}
	return;
}
ll C(ll tx,ll ty){
	return (fac[tx]/fac[tx-ty]/fac[ty])%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1)fg=0;
	}
	if(n<=11){
		dfs(0);
		write(st.size()%mod);
	}else if(fg){
		fac[0]=1,fac[1]=1;
		for(ll i=2;i<=n;i++)fac[i]=(fac[i-1]%mod*i%mod)%mod;
		for(ll i=3;i<=n;i++)ans=(ans+C(n,i))%mod;
		write(ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
