#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5;
struct edge{
	int u;
	int v;
	long long w;
};
int n,m,k;
int mx;
int cnt;
int f[MAXN];
int c[15][MAXN];
vector<edge> e;
long long ans;
map<pair<int,int>,int> mp;

void add(int x){
	if(x>mx) return ;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mp.find({i,j})==mp.end()||mp[{i,j}]>c[x][0]+c[x][i]+c[x][j]){
				mp[{i,j}]=c[x][0]+c[x][i]+c[x][j];
			}
		} 
	}
	return ;
}

int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e.push_back({x,y,z});
		mp[{x,y}]=z;
		mx=max(mx,z);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	for(int j=1;j<=k;j++){
		add(j);
	}
	for(auto p:mp){
		e.push_back({p.first.first,p.first.second,p.second});
	}
	sort(e.begin(),e.end(),cmp);
	for(int j=1;j<=n;j++) f[j]=j;
	for(edge j:e){
		int fa=find(j.u);
		int fb=find(j.v);
		if(fa!=fb){
			f[fa]=fb;
			ans+=j.w;
			cnt++;
		}
		if(cnt>=n) break;
	}
	cout<<ans;
	return 0;
}

