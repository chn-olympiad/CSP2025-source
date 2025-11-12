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

struct node {
	ll u,v,w;
	bool operator < (const node cmp) const {
		return w<cmp.w;
	}
};


const ll N=2e6+10,M=1e4+10,inf=1e14;
node seg[N],edge[N],edge2[N];
ll n,m,k,cnt=0;
ll c[15],mp[15][M],fa[N];
ll E=0;

ll myfind(ll id){
	if(fa[id]==id){
		return id;
	}
	return fa[id]=myfind(fa[id]);
}

ll put(ll x){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		edge2[i]=edge[i];
	}
	ll tot=cnt,now=n,ret=0;
	for(int i=0;i<10;i++){
		if(x & (1<<i)){
			now++;
			ret+=c[i+1];
			for(int j=1;j<=n;j++){
				edge2[++tot]=(node){n+i+1,j,mp[i+1][j]};
			}	
		}
	}
	sort(edge2+1,edge2+tot+1);
	
	ll cnt=0;
	for(int i=1;i<=tot;i++){
		ll fx=myfind(edge2[i].u),fy=myfind(edge2[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ret+=edge2[i].w;
			cnt++; 
		}
		if(cnt==now-1){
			return ret;
		}	
	}
	return ret;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		ll u=read(),v=read(),w=read();
		seg[i]=(node){u,v,w};
	}
	
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			mp[i][j]=read();
		}
	}
	
	sort(seg+1,seg+m+1);
	for(int i=1;i<=m;i++){
		ll fx=myfind(seg[i].u),fy=myfind(seg[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			cnt++;
			edge[cnt]=(node){seg[i].u,seg[i].v,seg[i].w};
		}
	} 
	
	ll ret=inf;
	for(int i=0;i<(1<<k);i++){
		ret=min(put(i),ret);
	}
	printf("%lld\n",ret); 
	
	return 0;
}
