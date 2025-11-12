#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<iostream>
int read(){
	int x=0,f=1;
	char ac=getchar();
	while(ac<'0'||ac>'9'){
		if(ac=='-') f=-1;
		ac=getchar();
	}
	while(ac>='0'&&ac<='9'){
		x=(x<<3)+(x<<1)+(ac-'0');
		ac=getchar();
	}
	return x*f;
}
const int inf=1e9+7;
struct edge{
	int u,v,w;
}e[1000005],now[1000005],res[1000005],c[15][10005];
bool operator <(edge a,edge b){
	return a.w<b.w;
}
long long ans;
int n,m,tot,k,val[15],fa[20005],id[15],cnt,num,p[15];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
long long solve(int S){
	long long sum=0;
	num=tot=0;
	id[++num]=0;
	for(int i=0;i<=k;i++) p[i]=1;
	for(int i=1;i<=k;i++){
		if(S&(1<<(i-1))){
			id[++num]=i;
			sum+=val[i];
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int blk=n+num-1;
	for(int i=1;i<=num*n;i++){
		int minx=2e9,pos=0;
		for(int j=1;j<=num;j++){
			if(p[id[j]]<=n&&c[id[j]][p[id[j]]].w<minx){
				minx=c[id[j]][p[id[j]]].w;
				pos=id[j];
			}
		}
		now[++tot]=c[pos][p[pos]];
		++p[pos];
	}	
	for(int i=1;i<=num*n;i++){
		if(blk==1) break;
		if(sum+1ll*(blk-1)*now[i].w>ans) return ans+1;
		int x=find(now[i].u),y=find(now[i].v);
		if(x^y){
			--blk;
			sum+=now[i].w;
			fa[y]=x;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		val[i]=read();
		for(int j=1;j<=n;j++){
			int ww=read();
			c[i][j]={j,n+i,ww};
		}
		std::sort(c[i]+1,c[i]+n+1);
	}
	std::sort(e+1,e+m+1);
	int blk=n;
	for(int i=1;i<=m;i++){
		if(blk==1) break;
		int x=find(e[i].u),y=find(e[i].v);
		if(x^y){
			fa[y]=x;
			ans+=e[i].w;
			res[++cnt]=e[i];
			--blk;
		}
	}
	for(int i=1;i<=cnt;i++) c[0][i]=res[i];
	c[0][++cnt]={1,1,inf};
	int lim=(1<<k);
	for(int S=1;S<lim;S++){
		long long sum=solve(S);
		ans=std::min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
