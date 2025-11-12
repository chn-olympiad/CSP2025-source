#include<bits/stdc++.h>
#define int long long
#define ALL(x) x.begin(),x.end()
using namespace std;
constexpr int N=1e4+11,M=1e6+1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
__inline void read(int&x){
	x=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return;
}
__inline void write(int x){
	if(x>=10)
		write(x/10);
	putchar((x%10)^48);
	return;
}
int n,m,k,fa[N],ans,edcnt,cst[11],wal[11][N],st=clock(),perm[11]={0,1,2,3,4,5,6,7,8,9,10};
//vector<pair<int,int> >e[N];
vector<tuple<int,int,int> >edges,tmp;
void initdsu(int nn){
	for(int i=0;i<=nn;i++)
		fa[i]=i;
	return;
}
int findfa(int x){
	return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
bool cmp(tuple<int,int,int>a,tuple<int,int,int>b){
	return(get<2>(a))<(get<2>(b));
}
int kruskal(int cnt){
	int res=0;
	edcnt=0;
	initdsu(n+k);
	sort(ALL(edges),cmp);
	for(auto ed:edges){
		int u=(get<0>(ed)),v=(get<1>(ed)),w=(get<2>(ed)),fau=findfa(u),fav=findfa(v);
		if(fau!=fav){
			edcnt++;
			res+=w;
			fa[fau]=fav;
		}
		if(edcnt==n+cnt-1)
			break;
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin),
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1,u,v,w;i<=m;i++){
		read(u),read(v),read(w);
		edges.push_back(make_tuple(u,v,w));
	}
	for(int i=1;i<=k;i++){
		read(cst[i]);
		for(int j=1;j<=n;j++)
			read(wal[i][j]);
	}
	initdsu(n);
	sort(ALL(edges),cmp);
	for(auto ed:edges){
		int u=(get<0>(ed)),v=(get<1>(ed)),w=(get<2>(ed)),fau=findfa(u),fav=findfa(v);
		if(fau!=fav){
			edcnt++;
			ans+=w;
			fa[fau]=fav;
			tmp.push_back(ed);
		}
		if(edcnt==n-1)
			break;
	}
	shuffle(perm+1,perm+k+1,rng);
	for(int s=1,res,cnt;s<(1<<k);s++){
		res=cnt=0,edges=tmp;
		for(int i=1;i<=k;i++)
			if((s>>(i-1))&1){
				int v=perm[i];
				res+=cst[v],cnt++;
				for(int j=1;j<=n;j++)
					edges.push_back(make_tuple(n+v,j,wal[v][j]));
			}
		ans=min(ans,res+kruskal(cnt));
		if(1.0*(clock()-st)/CLOCKS_PER_SEC>0.98)
			break;
	}
	write(ans);
	return 0;
}
