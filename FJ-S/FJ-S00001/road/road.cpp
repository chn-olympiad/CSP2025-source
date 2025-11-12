#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register char c=getchar();
	register int x=0;
	for(;(c<48)||(c>57);c=getchar());
	for(;(47<c)&&(c<58);c=getchar()){
		x=(x<<1)+(x<<3)+c-48;
	}
	return x;
}
#define ll long long
struct node{
	int x,y,z;
}e[1000010],w[20010];
inline bool cmp1(node xx,node yy){
	return xx.z<yy.z;
}
int fa[20010],sze[20010];
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int val[21];
struct edgnw{
	int id,x,y,z;
}a[200010];
inline bool cmp2(edgnw xx,edgnw yy){
	return xx.z<yy.z;
}
ll c[21];
bool vis[21];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read(),u,v,js=0,tot=0,x,nwcnt,nw;	
	ll ans=1e15,sum;
	for(register int i=1;i<=m;++i){
		e[i].x=read();e[i].y=read();e[i].z=read();
	}
	sort(e+1,e+m+1,cmp1);
	for(register int i=1;i<=n;++i){
		fa[i]=i,sze[i]=1;
	}
	sum=0;
	for(register int i=1;i<=m;++i){
		u=find(e[i].x),v=find(e[i].y);
		if(u!=v){
			w[++js]=e[i];
			if(sze[u]<sze[v]){
				fa[u]=v;
				sze[v]+=sze[u];
			}
			else{
				fa[v]=u;
				sze[u]+=sze[v];
			}
			sum+=e[i].z;
		}
	}
	ans=sum;
	for(register int i=1;i<=js;++i){
		a[++tot]={0,w[i].x,w[i].y,w[i].z};
	}
	for(register int i=1;i<=k;++i){
		c[i]=read();
		for(register int j=1;j<=n;++j){
			x=read();
			a[++tot]={i,n+i,j,x};
		}
	}
	sort(a+1,a+tot+1,cmp2);
	for(register int S=0;S<=(1<<k)-1;++S){
		vis[0]=true;
		sum=0;
		nwcnt=n;
		for(register int i=1;i<=k;++i){
			if(S&(1<<(i-1))){
				vis[i]=true;
				sum+=c[i];
				++nwcnt;
			}
			else{
				vis[i]=false;
			}
		}
		for(register int i=1;i<=n+k;++i){
			fa[i]=i,sze[i]=1;
		}
		nw=0;
		for(register int i=1;i<=tot;++i){
			if(vis[a[i].id]){
				u=find(a[i].x),v=find(a[i].y);
				if(u!=v){
					sum+=a[i].z;
					++nw;
					if(sze[u]<sze[v]){
						fa[u]=v;
						sze[v]+=sze[u];
					}
					else{
						fa[v]=u;
						sze[u]+=sze[v];
					}
				}
				if(nw==nwcnt-1){
					break;
				}
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
