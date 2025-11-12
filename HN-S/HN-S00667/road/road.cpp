#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e4 + 10;
struct edge{
	int to,val;
};
struct edge2{
	int from,to,val;
};
edge2 edges[2000ll*MAXN],cedge[MAXN],cedges[100*MAXN];
vector<edge>G[MAXN];
int n,m,k,fa[MAXN],sum=0,ans=LLONG_MAX,cnt=0;
int p[11][MAXN];
bool choice[11];
int getfa(int x){
	if(fa[x]!=x) fa[x]=getfa(fa[x]);
	return fa[x];
}
bool cmp(edge2 x,edge2 y){
	return x.val<y.val;
}

void bfs(){
	priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > >e;
	for(int i=1;i<=n;i++){
		if(fa[i]!=1) {
			int maxn = LLONG_MAX;
			for(int j=1;j<=k;j++){
				if(!choice[j]) continue;
				maxn=min(maxn,p[j][1]+p[j][i]);
//				e.push({p[j][1]+p[j][i],i});
			}
			if(maxn<LLONG_MAX) e.push({maxn,i});
		}
	}
	for(int i=0;i<G[1].size();i++){
		bool flag=1;
		int mv=LLONG_MAX,m1;
		for(int j=1;j<=k;j++){
			if(!choice[j]) continue;
			if(p[j][1]+p[j][G[1][i].to]<G[1][i].val){
				flag=0;
				if(mv>p[j][1]+p[j][G[1][i].to]){
					mv=p[j][1]+p[j][G[1][i].to];
					m1=G[1][i].to;
				}
			}
		}
		if(flag) e.push({G[1][i].val,G[1][i].to});
		else e.push({mv,G[1][i].to});
	}
	int cnt2=1;
	while(cnt2<n){
		pair<int,int>sx=e.top();e.pop();
		if(getfa(sx.second)==getfa(1)){
			continue;
		}
		
		fa[sx.second]=getfa(1);
		sum+=sx.first;cnt2++;
//		cout<<sx.second<<" "<<sum<<"  ";
		for(int i=1;i<=n;i++){
			if(fa[i]!=1) {
				int maxn = LLONG_MAX;
				for(int j=1;j<=k;j++){
					if(!choice[j]) continue;
					maxn=min(maxn,p[j][sx.second]+p[j][i]);
	//				e.push({p[j][1]+p[j][i],i});
				}
				if(maxn<LLONG_MAX) e.push({maxn,i});
			}
		}
		for(int i=0;i<G[sx.second].size();i++){
			if(getfa(G[sx.second][i].to)==getfa(1)) continue;
			bool flag=1;
			int mv=LLONG_MAX,m1;
			for(int j=1;j<=k;j++){
				if(!choice[j]) continue;
				if(p[j][sx.second]+p[j][G[sx.second][i].to]<G[sx.second][i].val){
					flag=0;
					if(mv>p[j][sx.second]+p[j][G[sx.second][i].to]){
						mv=p[j][sx.second]+p[j][G[sx.second][i].to];
						m1=G[sx.second][i].to;
					}
				}
			}
			if(flag) e.push({G[sx.second][i].val,G[sx.second][i].to});
			else e.push({mv,G[sx.second][i].to});
		}
	}
}
void check()
{
	 
	sum=0ll;
	int lm=m;
	for(int i=1;i<=m;i++){
		edges[i]=cedges[i];
	}
	for(int i=1;i<=k;i++){
		if(choice[i]){
//			cout<<i<<" ";
			sum+=p[i][0];
			if(sum>=ans) return;
			for(int e=1;e<=n;e++){
				for(int j=e+1;j<=n;j++){
					if(e==j){
						continue;
					}
					if(p[i][e]+p[i][j]>edges[m].val) continue;
					edges[++lm].val=p[i][e]+p[i][j];
					edges[lm].from=e;
					edges[lm].to=j;
//					cout<<e<<" "<<j<<"-"<<p[i][e]+p[i][j]<<"\n";
				}
			}
		}
	}
//	cout<<"\n";
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(edges+1,edges+1+lm,cmp);
	int cnt=1;
	for(int i=1;i<=lm and cnt<=n;i++){
		if(getfa(edges[i].from)!=getfa(edges[i].to)){
//			cout<<edges[i].from<<edges[i].to<<edges[i].val<<"\n";
//			G[edges[i].from].emplace_back(edges[i].to,edges[i].val);
//			G[edges[i].to].emplace_back(edges[i].from,edges[i].val);
			fa[getfa(edges[i].from)]=getfa(edges[i].to);
			sum+=edges[i].val;
			cnt++;
			if(sum>=ans) return;
		}
	}
//	cout<<sum<<"\n\n";
	ans=min(ans,sum);
	return;
}
void dfs(int x){
	if(x>k) {
		check();
		return;
	}
	choice[x]=0;
	dfs(x+1);
	choice[x]=1;
	dfs(x+1);
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,t,w;
		cin>>u>>t>>w;
		edges[i]={u,t,w};
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>p[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(edges+1,edges+1+m,cmp);
	for(int i=1;i<=m;i++) cedges[i]=edges[i];
	if(k==0){
		
		for(int i=1;i<=m;i++){
			if(getfa(edges[i].from)!=getfa(edges[i].to)){
	//			G[edges[i].from].emplace_back(edges[i].to,edges[i].val);
	//			G[edges[i].to].emplace_back(edges[i].from,edges[i].val);
				fa[getfa(edges[i].from)]=getfa(edges[i].to);
				cedge[++cnt]=edges[i];
				sum+=edges[i].val;
			}
		}
		cout<<sum;
		return 0;
	}
//	choice[1]=1;
	dfs(1);
//	check();
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
