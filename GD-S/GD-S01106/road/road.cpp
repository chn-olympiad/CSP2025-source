#include <bits/stdc++.h>
using namespace std;
const int N=1e4+8,M=4e6+8;
struct node{int x,y;long long z;} p[M];
struct node2{long long z;int x;} w[N];
int n,m,k,lp=1,cnt=0,fa[N],link[N];
priority_queue <pair<long long,int> > sta;
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
bool cmp(node nx,node mx){return nx.z<mx.z;}
bool cmp2(node2 nx,node2 mx){return nx.z<mx.z;}
long long solve(){
	sort(p+1,p+1+cnt,cmp);
	long long ans=0;
	for (int i=1;i<=n;++i) fa[i]=i;
	for (int i=1;i<=cnt;++i){
		if (find(p[i].x)!=find(p[i].y)){
			fa[find(p[i].x)]=find(p[i].y);
			ans+=p[i].z;
			++lp;
		}
		if (lp==n) break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >>n>>m>>k;
	long long z;
	for (int i=1,x,y;i<=m;++i){
		cin >>x>>y>>z;
		p[++cnt]={x,y,z};
	}
	while (k--){
		cin >>z;
		for (int i=1;i<=n;++i) cin >>w[i].z,w[i].x=i,fa[i]=i;
		sort(w+1,w+1+n,cmp2);
		for (int i=1;i<n;++i) link[i]=i+1,sta.push({-(w[i].z+w[i+1].z+z),i});
		for (int i=1;i<n;++i){
			pair <long long,int> u=sta.top();sta.pop();
			if (find(u.second)==find(link[u.second])){--i;continue;}
			p[++cnt]={w[u.second].x,w[link[u.second]].x,-u.first};
			fa[find(u.second)]=find(link[u.second]);
			++link[u.second];
			if (link[u.second]<=n) sta.push({-(w[u.second].z+w[link[u.second]].z+z),u.second});
		}
		while (!sta.empty()) sta.pop();
	}
	cout <<solve();
	return 0;
}
