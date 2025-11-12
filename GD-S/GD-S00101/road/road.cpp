#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+5;
ll n,m,k,x,cnt,c[N],fa[N],sum,ans=1e14,y,u,v,w;
bool flag=1;
struct node{
	ll u,v,w;
	bool flag;
}d[N];
bool cmp(node l,node r){
	return l.w<r.w;
}
ll find(ll x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
ll read(){
	char ch=getchar();
	ll x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		d[i]=node({u,v,w,0});
//		printf("%d\n",i);
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]) flag=0; 
		for(int j=1;j<=n;j++){
			y=read();
			d[++cnt]=node({i+n,j,c[i]+y,1});
		}
	}
	sort(d+1,d+cnt+1,cmp);
	if(!flag){
		for(int i=0;i<(1<<(k+1));i++){
			sum=0;
			for(int j=1;j<=n;j++) fa[j]=j;
			for(int j=1;j<=k;j++) if((i>>(j-1))&1) sum+=c[j];
			for(int j=1;j<=cnt;j++){
				if(d[j].flag&&!((i>>(d[j].u-1))&1)) continue;
				int x=find(fa[d[j].u]),y=find(fa[d[j].v]);
				if(x==y) continue;
				sum+=d[j].w;
				fa[x]=y;
			}
			ans=min(ans,sum);
		}		
	}
	else{
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=cnt;j++){
			x=find(fa[d[j].u]),y=find(fa[d[j].v]);
			if(x==y) continue;
			sum+=d[j].w;
			fa[x]=y;
		}
		ans=sum;
	}
	printf("%lld\n",ans);
	return 0;
}
