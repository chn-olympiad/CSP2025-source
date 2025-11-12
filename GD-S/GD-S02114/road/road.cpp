#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

//充分相信重建的边都在最小生成树上，对最小生成树做树形DP+状压DP，设f[u][S]为选了S这个乡镇且必须使用每一个乡镇中u子树联通的最小花费，f[u][0]预处理，f[u][S]=\sum_{fa[v]=u}(f[v][S]+min(uv树边距离，开了乡镇之后的该边最小值)),答案即为min f[1][S]
const int M=1e6+10,N=1e4+10,K=11;
int n,m,k,c[K],f[N][1<<K],fa[N],p[K][N],e[N<<1],ne[N<<1],h[N],idx,w[N<<1],ans;
struct edge{
	int u,v,w;
}E[M<<1];

bool cmp(edge n1,edge n2){
	return n1.w<n2.w;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void merge(int x,int y){
	fa[x]=y;
}

void add(int u,int v,int q){
	e[++idx]=v;
	ne[idx]=h[u];
	w[idx]=q;
	h[u]=idx;
}

void dfs1(int u,int fr){
	fa[u]=fr;
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(v==fr){
			continue;
		}
		dfs1(v,u);
		f[u][0]+=f[v][0]+w[i];
	}
}

void dfs2(int u,int fr,int S){
	for(int j=0;j<k;++j){
		if((S>>j)&1){
			f[u][S]+=p[j+1][u];
		}
	}
	bool fl=1;
	int st=0;
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(v==fr){
			continue;
		}
		dfs2(v,u,S);
		fl=0;
		int mi=f[v][0]+w[i];
		for(int j=0;j<k;++j){
			if((S>>j)&1){
				int q=mi;
				mi=min(mi,min(p[j+1][v]+f[v][S^(1<<j)],f[v][S]));
				if(q!=mi){
					st|=(1<<j);
				}
			}
		}
		f[u][S]+=mi;
	}
	if(fl)return;
	for(int j=0;j<k;++j){
		if(((S^st)>>j)&1){
			f[u][S]-=p[j+1][u];
		}
	}
}

void dfs3(int u,int fr,int S){
	f[u][S]=1e12;
	for(int st=1;st<S;++st){
		int res=0;
		for(int j=0;j<k;++j){
			if((st>>j)&1){
				f[u][S]+=p[j+1][u];
			}
		}
		for(int i=h[u];i;i=ne[i]){
			int v=e[i];
			if(v==fr){
				continue;
			}
			dfs3(v,u,S);
			int mi=f[v][0]+w[i];
			for(int j=0;j<k;++j){
				if((st>>j)&1){
					mi=min(mi,min(p[j+1][v]+f[v][S^(1<<j)],f[v][S]));
				}
			}
			res+=mi;
		}
		f[u][S]=min(f[u][S],res);
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>p[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	sort(E+1,E+m+1,cmp);
	for(int i=1;i<=m;++i){
		int x=find(E[i].u),y=find(E[i].v);
		if(x!=y){
			merge(x,y);
			add(E[i].u,E[i].v,E[i].w);
			add(E[i].v,E[i].u,E[i].w);
//			cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<endl;
		}
	}
	dfs1(1,0);//初始化，计算f[u][0]
	ans=f[1][0];
//	if(k>5){
		for(int S=1;S<(1<<k);++S){//遍历乡镇集合 
			dfs2(1,0,S);
			int ct=0;
			for(int j=0;j<k;++j){
				if((S>>j)&1){
					ct+=c[j+1];
				}
			}
			ans=min(ans,f[1][S]+ct);
		}
//	}else{
//		for(int S=1;S<(1<<k);++S){
//			dfs3(1,0,S);
//			int ct=0;
//			for(int j=0;j<k;++j){
//				if((S>>j)&1){
//					ct+=c[j+1];
//				}
//			}
//			ans=min(ans,f[1][S]+ct);
//		}
//	}
//	for(int j=0;j<(1<<k);++j){
//		for(int i=1;i<=n;++i){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<ans;
	return 0;
}
