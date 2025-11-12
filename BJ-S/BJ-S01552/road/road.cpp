#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=10010,M=1000010;
vector<pair<int,ll>>g[N];
int n,m,k,u,v;
ll w;
ll c[20],a[20][N];
struct edge{
	int u,v;
	ll w;
	bool operator<(const edge &a)const{
		return w<a.w;
	}
}e[M+20*N];
//bool cmp(const edge &a,const edge &b){
//	return a.w<b.w;
//}
queue<edge>st;
set<pair<int,int>>newe;
int fa[N];
int find(int x){
	return (fa[x]==x?fa[x]:fa[x]=find(fa[x]));
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	fa[fy]=fx;
}
bool judge(int x,int y){
	return find(x)==find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		scanf("%lld",&w);
		e[i]={u,v,w};
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	//bool flag=true;
	for(int i=1;i<=k;i++){
		scanf("%lld",c+i);
		//if(c[i]!=0)flag=false;
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	//if(k==0){//16pts
		ll ans=0;
		int cnt=0;
		sort(e+1,e+1+m);
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u);
			int fy=find(e[i].v);
			if(fx!=fy){
				ans+=e[i].w;
				fa[fy]=fx;
				cnt++;
			}
			if(cnt==n-1)break;
		}
		printf("%lld\n",ans);
		return 0;
	//}
	/*
	if(flag){
		ll ans=0;
		int cnt=0;
		sort(e+1,e+1+m);
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u);
			int fy=find(e[i].v);
			if(fx!=fy){
				ans+=e[i].w;
				fa[fy]=fx;
				st.push({e[i].u,e[i].v,e[i].w});
				cnt++;
			}
			if(cnt==n-1)break;
		}
		while(!st.empty()){
			edge t=st.front();
			st.pop();
			int mn=2147483647,mnp;
			for(int j=1;j<=k;j++){
				if((newe.count({t.u,n+j})?0:a[j][t.u])+(newe.count({t.v,n+j})?0:a[j][t.v])<t.w){
					if((newe.count({t.u,n+j})?0:a[j][t.u])+(newe.count({t.v,n+j})?0:a[j][t.v])<mn){
						mnp=j;
						mn=(newe.count({t.u,n+j})?0:a[j][t.u])+(newe.count({t.v,n+j})?0:a[j][t.v]);
					}
				}
			}
			if(mn!=2147483647)ans=ans-t.w+mn;
			newe.insert({t.u,mnp+n});
			newe.insert({t.v,mnp+n});
		}
		printf("%lld\n",ans);
		return 0;
	}*/
	return 0;
}
