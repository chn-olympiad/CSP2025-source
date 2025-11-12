#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll uv[3010][3010],c[13][10500],tuv[3010][3010];
ll mnw=999999999999;
int mni;
struct node {
	int u,v;
	ll w;
} mm[1000050];
bool operator>(const node x,const node y) {
	return x.w > y.w;
}
struct ppp {
	vector<int> to;
	int cnt;
} pp[10050];
ll ann=100000000000000000,ww;
int uu,vv;
int n,m,k;
ll fd(int mi) {
	priority_queue<node,vector<node>,greater<node> > q;
	bool vis[10050]= {false};
	q.push({0,mm[mi].u,0});
	ll ans=0;
	node xy;
	while(!q.empty()) {
		xy=q.top();
		q.pop();
		if(vis[xy.v]) continue;
		vis[xy.v]=1;
		ans+=xy.w;
		for(int k=1; k<=pp[xy.v].cnt; k++) {
			if(!vis[pp[xy.v].to[k-1]]) {
				q.push({xy.v,pp[xy.v].to[k-1],uv[xy.v][pp[xy.v].to[k-1]]});
			}
		}
	}
	return ans;
}
bool bu[100];
void ty() {
	ll anss=0,ttt=mnw;
	int tt=mni;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) uv[i][j]=tuv[i][j];
	for(int cc=1; cc<=k; cc++) {
		if(bu[cc]) {
			anss+=c[cc][0];
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					if(i==j)continue;
					uv[i][j]=min(uv[i][j],c[cc][i]+c[cc][j]);
					if(ttt>uv[i][j]) {
						ttt=uv[i][j];
						tt=i;
					}
				}
			}
		}
	}
	anss+=fd(tt);
	ann=min(ann,anss);
}
void dfs(int cx) {
	if(cx==k+1) {
		ty();
		return;
	}
	dfs(cx+1);
	bu[cx]=1;
	dfs(cx+1);
	bu[cx]=0;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) tuv[i][j]=1000000000000000000;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%lld",&uu,&vv,&ww);
		mm[i].u=uu;
		mm[i].v=vv;
		mm[i].w=ww;
		tuv[uu][vv]=tuv[vv][uu]=ww;
		if(ww<mnw) {
			mnw=ww;
			mni=i;
		}
		pp[uu].to.push_back(vv);
		pp[vv].to.push_back(uu);
		pp[uu].cnt++;
		pp[vv].cnt++;
	}
	bool ck=0;
	for(int i=1; i<=k; i++) {
		for(int l=0; l<=n; l++) {
			scanf("%lld",&c[i][l]);
			if(c[i][l]!=0) ck=1;
		}
	}
	if(ck==0&&k!=0) {
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ann;
	return 0;
}
