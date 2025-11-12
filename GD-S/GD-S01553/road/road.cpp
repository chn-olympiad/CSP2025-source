#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define int long long
using namespace std;
const int MAX=1ll<<60;
typedef pair<int,int> pii;
int n,m,k,st,a[15][10005],ans=MAX,bad[15],v[10050],A=1;
vector<pii> ed[10005];
priority_queue<pii,vector<pii>,greater<pii> > pq;
vector<int> dig;
int initdig() {
	dig.clear();
	int ts=st,cnt=0;
	while(ts) {
		while((ts&1)==0) {ts>>=1,++cnt;}
		if(bad[cnt]) return 1;
		dig.push_back(-~cnt);
		ts>>=1;
	}
	return 0;
}
void addedge(int x) {
	v[x]=1;
	if(x<=n) {
		for(int i=0;i<ed[x].size();++i) {
			if(v[ed[x][i].second]) continue;
			pq.push(ed[x][i]);
		}
		for(int i=0;i<dig.size();++i) {
			if(v[n+dig[i]]) continue;
			pq.push({a[dig[i]][x],n+dig[i]});
		}
	}
	else {
		x-=n;
		for(int i=1;i<=n;++i) {
			if(v[i]) continue;
			pq.push({a[x][i],i});
		}
	}
}
void calc() {
	int res=0,cnt1=1,cnt2=0;
	if(initdig()) return;
	for(int i=0;i<dig.size();++i) {
		res+=a[dig[i]][0];
	}
	memset(v,0,sizeof(v));
	while(!pq.empty()) pq.pop();
	addedge(1);
	while(cnt1<n) {
		pii now;
		while(1) {
			now=pq.top();
			pq.pop();
			if(!v[now.second]) break;
		}
		addedge(now.second);
		res+=now.first;
		if(now.second>n) ++cnt2;
		else ++cnt1;
	}
	for(int i=0;i<dig.size();++i) {
		if(!v[dig[i]]) bad[dig[i]]=1;
	}
	ans=min(ans,res);
}
void work() {
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i) {
		cin>>u>>v>>w;
		ed[u].push_back({w,v});
		ed[v].push_back({w,u});
	}
	for(int i=1;i<=k;++i) {
		int e0=0;
		for(int j=0;j<=n;++j) {
			cin>>a[i][j];
			if(a[i][j]==0) {
				if(j) e0=1;
			}
			else {
				if(j==0) A=0;
			}
		}
		if(!e0) A=0;
	}
	int mn=1<<k;
	if(A) {
		for(int i=1;i<=k;i++) {
			int ii;
			for(int j=1;j<=n;j++) {
				if(a[i][j]==0) {
					ii=j;break;
				}
			}
			for(int j=1;j<=n;j++) {
				if(ii==j) continue;
				ed[ii].push_back({a[i][j],j});
				ed[j].push_back({a[i][j],ii});
			}
		}
		calc();
	}
	else {
		for(;st<mn;++st) {
			calc();
		}
	}
	cout<<ans;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t=1;
//	cin>>t;
	while(t--) {
		work();
	}
	return 0;
}
