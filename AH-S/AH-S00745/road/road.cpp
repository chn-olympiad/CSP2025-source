#include<bits/stdc++.h>
using namespace std;
//Save n-1 edges first.
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e4+20;
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
struct edge{
	int u,v,w;bool bo;
}e[N*100],f[10][N];
int n,m,k,fa[N],sz[N],a[10][N],b[10],p[11];ll ans;
bool cmp1(edge A,edge B){return A.w<B.w;}
int find(int x){return x==fa[x]? x:fa[x]=find(fa[x]);}
bool cmp2(edge A,edge B){return A.bo>B.bo;}
priority_queue<pii,vector<pii>,greater<pii>> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	sort(e+1,e+m+1,cmp1);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		int tx=find(e[i].u),ty=find(e[i].v);
		if(tx==ty)continue;
		if(sz[tx]>sz[ty])swap(tx,ty);
		fa[tx]=ty;sz[ty]+=sz[tx];ans+=e[i].w;e[i].bo=1;
	}
	sort(e+1,e+m+1,cmp2);m=n-1;
	sort(e+1,e+m+1,cmp1);
	for(int i=0;i<k;i++){
		b[i]=read();
		for(int j=1;j<=n;j++)
			f[i][j]={j,n+1+i,read(),0};
		sort(f[i]+1,f[i]+n+1,cmp1);
	}
	for(int S=1;S<(1<<k);S++){
		ll s=0;
		for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
		for(int i=0;i<k;i++)
			if(S&(1<<i)){
				s+=b[i];p[i]=1;
				q.push({f[i][1].w,i});
			}
		q.push({e[1].w,k});p[k]=1;
		int cnt=0;
		while(!q.empty()){
			int u=q.top().second,o=p[u],ww=q.top().first;q.pop();
			int tx=(u<k? find(f[u][o].u):find(e[o].u)),ty=(u<k? find(f[u][o].v):find(e[o].v));
			if(tx!=ty){
				if(sz[tx]>sz[ty])swap(tx,ty);
				fa[tx]=ty;sz[ty]+=sz[tx];
				s+=ww;cnt++;
			}
			p[u]++;
			if(u==k&&p[k]<n)q.push({e[p[k]].w,u});
			if(u<k&&p[u]<=n)q.push({f[u][p[u]].w,u});
		}
		ans=min(ans,s);
	}
	cout<<ans;
}