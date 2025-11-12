#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+7;
ll n,m,k,a[17][N],c[N],u,v,w,ans;
struct node{
	ll u,v,w;
}e[N<<1],E[N<<1];
ll tot=0,cnt=0;
ll read(){
	ll res=0;
	char r=getchar();
	while(r<'0'||r>'9')r=getchar();
	while(r>='0'&&r<='9')res=res*10+r-'0',r=getchar();
	return res;
}
void add(ll x,ll y,ll z){
	e[++tot].u=x;
	e[tot].v=y;
	e[tot].w=z;
}
ll fa[N];
ll find(ll x){return fa[x]==x?x:fa[x]=find(fa[x]);}
ll Kru(bool flag){
	for(ll i=1;i<=n+k;i++)fa[i]=i;
	ll res=0;
	for(ll i=1;i<=tot;i++){
		ll U=find(e[i].u),V=find(e[i].v);
		if(U!=V){
			fa[U]=V;
			if(flag)E[++cnt]=e[i];
			res+=e[i].w;
		}
	}
	return res;
} 
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		add(u,v,w);
	}
	for(ll i=1;i<=k;i++){
		c[i]=read();
		for(ll j=1;j<=n;j++){
			a[i][j]=read(); 
		}
	}
	sort(e+1,e+1+tot,cmp);
	ans=Kru(1);
	for(ll i=1;i<(1<<k);i++){
		tot=0;
		ll res=0;
		for(ll j=1;j<=k;j++)
			if((i>>(j-1))&1){
				res+=c[j];
				for(ll p=1;p<=n;p++)add(j+n,p,a[j][p]);
			}
		for(ll j=1;j<=cnt;j++)
			add(E[j].u,E[j].v,E[j].w);
		sort(e+1,e+1+tot,cmp);
		ans=min(ans,Kru(0)+res);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
