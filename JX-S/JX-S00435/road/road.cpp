#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int d[10500][10500];
int tot[10500];
int yu[10500][10500];
int a[10500];
long long s[10500];
bool op[10500];
int c[50];
priority_queue<pair<int ,pair<int ,int>>>q;
long long ans = 0;
void di(){
	memset(s,0x3f,sizeof(s));
	s[1]=0;
	q.push(make_pair(0,make_pair(0,1)));
	while(q.size()){
		int x = q.top().second.second;
		int ty = q.top().second.first;
		q.pop();
		if(op[x]==1)
			continue;
		op[x] = 1;
		ans += ty;
		for(int i=1;i<=tot[x];++i){
			int y = yu[x][i];
			if(op[y]==1)
				continue;
			if( d[x][y] + s[x] <s[y]){
				s[y] = s[x] + d[x][y];
				q.push(make_pair(-s[y],make_pair(d[x][y],y)));
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		d[u][v] = w;
		yu[u][++tot[u]] = v;
		d[v][u] = w;
		yu[v][++tot[v]] = u;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[j];
		}
	}
	di();
	cout<<ans;
	return 0;
}
