#include<bits/stdc++.h>
using namespace std;
#define FILE "road"
int n,m,k;
struct edge{
	int u,v;
	long long w;
	bool operator<(const edge &rhs) const{
		return w<rhs.w;
	}
}es[2000001],tmp[2000001];
bool builded[21];
long long c[21],a[21][10001];
int fa[100001];
int ids[21];
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
long long kruskal(int m){
	for(int i=1;i<=n+2*k;i++){
		fa[i]=i;
	}
	long long ans=0;
	sort(es+::m+1,es+m+1);
	merge(es+1,es+::m+1,es+::m+1,es+m+1,tmp+1);
	for(int i=1;i<=m;i++){
		int u=tmp[i].u,v=tmp[i].v;
		long long w=tmp[i].w;
		if(find(u)==find(v))	continue;
		ans+=w;
		fa[find(u)]=find(v);
	}
	return ans;
}
mt19937 rse(time(0));
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> es[i].u >> es[i].v >> es[i].w;
	}
	sort(es+1,es+m+1);
	long long ans=kruskal(m);
	int ecnt=m;
	for(int i=1;i<=k;i++){
		cin >> c[i];
		ids[i]=i;
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	if(m<=100000 || k<=5){
		for(int _=0;_<(1<<k);_++){
			int ecnt=m;
			for(int i=1;i<=k;i++){
				if(_>>(i-1)&1){
					es[++ecnt]=edge({n+2*i-1,n+2*i,c[i]});
					for(int j=1;j<=n;j++){
						es[++ecnt]=edge({n+2*i-1,j,a[i][j]});
					}
				}
			}
			ans=min(ans,kruskal(ecnt));
		}
		cout << ans;
		return 0;
	}
	sort(ids+1,ids+k+1,[](int i,int j){
		return c[i]<c[j];
	});
	for(int _=1;_<=k;_++){
		int i=ids[_];
		int nwecnt=ecnt;
		ids[i]=i;
		es[++nwecnt]=edge({n+2*i-1,n+2*i,c[i]});
		for(int j=1;j<=n;j++){
			es[++nwecnt]=edge({n+2*i-1,j,a[i][j]});
		}
		long long tmp=kruskal(nwecnt);
		if(tmp<=ans){
			ans=tmp;
			ecnt=nwecnt;
		}
	}
//	for(int _t=0;_t<2;_t++){
//		shuffle(ids+1,ids+k+1,rse);
//		for(int _=1;_<=k;_++){
//			int i=ids[_];
//			int nwecnt=ecnt;
//			ids[i]=i;
//			es[++nwecnt]=edge({n+2*i-1,n+2*i,c[i]});
//			for(int j=1;j<=n;j++){
//				es[++nwecnt]=edge({n+2*i-1,j,a[i][j]});
//			}
//			long long tmp=kruskal(nwecnt);
//			if(tmp<=ans){
//				ans=tmp;
//				ecnt=nwecnt;
//			}
//		}
//	}
	
	cout << ans;
	return 0;
}
/*
我们有m条边和nk条特殊边
每一类特殊边第一次使用后会额外产生c的费用
 
*/
