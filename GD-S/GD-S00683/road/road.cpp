#include<bits/stdc++.h>
#define K 15
#define N 10005
#define M 1000005
#define getc getchar_unlocked
using namespace std;
bool tag[N];
long long ans=LLONG_MAX;
struct xs{int u,v,w;}ed[M+K*N];
int n,m,k,fa[N+K],c[K],a[K][N];
int zbb(int x){return fa[x]?fa[x]=zbb(fa[x]):x;}
void read(int &x){
	x=0;char c=getc();
	while(c<'0'||c>'9') c=getc();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getc();
}
void dfs(int x,long long sum){
	if(sum>=ans) return; 
	if(x>k){
		int cnt=n,tot=m;
		for(int i=1;i<=k;i++)
			if(tag[i]){
				cnt++;
				for(int j=1;j<=n;j++)
					ed[++tot]={j,n+i,a[i][j]};
			}
		memset(fa,0,sizeof fa);
		sort(ed+1,ed+tot+1,[](xs x,xs y){return x.w<y.w;});
		for(int i=1;i<=tot;i++){
			int x=zbb(ed[i].u),y=zbb(ed[i].v);
			if(x!=y) fa[x]=y,sum+=ed[i].w,cnt--;
			if(cnt==1) break;
		}
		ans=min(ans,sum);
		return;
	}
	tag[x]=false,dfs(x+1,sum);
	tag[x]=true,dfs(x+1,sum+c[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1,u,v,w;i<=m;i++)
		read(u),read(v),read(w),ed[i]={u,v,w};
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++)
			read(a[i][j]);
	}
	dfs(1,0),printf("%lld",ans);
	return 0;
}
