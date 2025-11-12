#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll read(){
	ll ans=0,w=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-'){
			w=-w;
		}
		s=getchar();
	}
	while(isdigit(s)){
		ans=(ans<<3LL)+(ans<<1LL)+(s^48);
		s=getchar();
	}
	return ans*w;
}

const ll N=505,mod=998244353;
char s[N];
ll a[N],c[N],d[N];
bitset<N> vis;
ll ret=0;
ll n,m;

void dfs(ll cur){
	if(cur==0){
		ll sum=0,now=0;
		for(int i=1;i<=n;i++){
			if(now>=d[i] || s[i]=='0'){
				now++;
			}
			else{
				sum++;
			}
		}
		if(sum>=m){
			ret++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		d[cur]=c[i];
		dfs(cur-1);
		vis[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+(s[i]=='0');
	}
	
	for(int i=1;i<=n;i++){
		c[i]=read();	
	}
	
	dfs(n);
	printf("%lld\n",ret%mod);
	
	return 0;
}
