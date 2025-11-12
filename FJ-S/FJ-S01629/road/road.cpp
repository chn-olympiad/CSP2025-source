#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+25,M=2e6+25;
ll n,m,k,p[N],c[15],a[15][N],ans,tot;
ll find(int x){
	return (p[x]==x) ?x : p[x]=find(p[x]);
}
struct node{
	ll u,v,w;
}g[M],e[M];
bool cmp(node x,node y){
	return x.w<y.w;	
}
ll read(){
	ll x=0,s=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') s=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		g[i].u=read();
		g[i].v=read();
		g[i].w=read();	
	}
	for(int j=1;j<=k;j++){
		c[j]=read();
		for(int i=1;i<=n;i++){
			a[j][i]=read();
		}
	}
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;tot<n&&i<=m;i++){
		int fx=find(g[i].u),fy=find(g[i].v);
		if(fx!=fy){
			p[fx]=fy;
			ans+=g[i].w;
			e[++tot].u=g[i].u;
			e[tot].v=g[i].v;
			e[tot].w=g[i].w;
		}
	}
	for(int i=1;i<=tot;i++){
		g[i].u=e[i].u;
		g[i].v=e[i].v;
		g[i].w=e[i].w;
	}
	for(int s=1;s<(1<<k);s++){
		tot=n-1;
		for(int i=1;i<=tot;i++){
			e[i].u=g[i].u;
			e[i].v=g[i].v;
			e[i].w=g[i].w;
		}
		ll res=0,num=0;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&s){
				num++;
				res+=c[j];
				if(res>ans) break;
				for(int i=1;i<=n;i++){
					e[++tot].u=n+num;
					e[tot].v=i;
					e[tot].w=a[j][i];
				}
			}
		}
		sort(e+1,e+1+tot,cmp);
		ll cnt=0;
		for(int i=1;i<=n+num;i++) p[i]=i;
		for(int i=1;cnt<n+num&&i<=tot;i++){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx!=fy){
				p[fx]=fy;
				res+=e[i].w;
				if(res>ans) break;
				++cnt;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}