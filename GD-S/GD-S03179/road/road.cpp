#include<bits/stdc++.h>
using namespace std;
#define int long long
void file(string fi){
	freopen((fi+".in").data(),"r",stdin);
	freopen((fi+".out").data(),"w",stdout);
} 
int n,m,k;
struct edge{
	int u,v,w;
	bool operator<(const edge&r)const{
		return w<r.w;
	}
};
vector<edge>es;
int co[20][10010];
const int maxn=1e4+10;
int a[maxn];
vector<edge>mer(const vector<edge>&l,const vector<edge>&r){
	vector<edge>ans;
	int p1=0,p2=0;
	for(;p1<l.size()||p2<r.size();){
		if(p1==l.size()&&p2<r.size())ans.push_back(r[p2]),++p2;
		else if(p2==r.size()&&p1<l.size())ans.push_back(l[p1]),++p1;
		else if(p1<l.size()&&p2<r.size()){
			if(l[p1]<r[p2])ans.push_back(l[p1]),++p1;
			else ans.push_back(r[p2]),++p2;
		}
		else break;
	}
	return ans;
}
int sum,ans=LLONG_MAX;
vector<int>fa;
vector<int>rk;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void uni(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		if(rk[x]>rk[y])swap(x,y);
		fa[x]=y;
		rk[y]+=rk[x];
	}
}
void sol(const vector<edge>&ci,int t){
	vector<edge> ed=mer(ci,es);
	fa.clear();
	rk.clear();
	fa.resize(n+k+1);
	rk.resize(n+k+1);
	for(int i=1;i<=n+k;++i)fa[i]=i,rk[i]=1;
	int ct=0;
	for(int i=0;i<ed.size();++i){
		if(sum>=ans)return;
		if(ct>=n+t-1)return;
		if(find(ed[i].u)==find(ed[i].v))continue;
		uni(ed[i].u,ed[i].v);
		sum+=ed[i].w;
		++ct;
	}
}
signed main(){
	file("road");
	cin>>n>>m>>k;
	for(int i=0,u,v,w;i<m;++i){
		cin>>u>>v>>w;
		es.push_back({u,v,w});
	}
	sort(es.begin(),es.end());
	for(int i=0;i<k;++i){
		cin>>a[i];
		for(int j=1;j<=n;++j)cin>>co[i][j];
	}
	for(int i=0;i<(1<<k);++i){
		vector<edge>ci;
		int t=0;
		for(int j=0;j<k;++j)
			if(i>>j&1){
				++t;
				sum+=a[j];
				for(int u=1;u<=n;++u){
					ci.push_back({j+n+1,u,co[j][u]});
				}
			}
		sort(ci.begin(),ci.end());
		sol(ci,t);
		ans=min(ans,sum);
		sum=0;
	}
	cout<<ans;
	return 0;
}
