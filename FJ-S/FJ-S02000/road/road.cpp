#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii=pair<int,int>;
int n,m,k;
vector<pii>v[1010];
int a[22][1010];
int mi=INF;
int d[1010];
int s[1010];

bool st[1010];
void dijistar(int x){
	memset(st,false,sizeof st);
	memset(d,INF,sizeof d);
	memset(s,INF,sizeof s);
	priority_queue<pii,vector<pii>,greater<>>q;
	
	q.push({0,x});
	d[x]=0;
	st[x]=1;
	s[x]=0;
	while(q.size()){
		auto t=q.top();
		st[t.second]=1;
		q.pop();
		for(auto i:v[t.second]){
			if(st[i.first]) continue;
			
			if(d[i.first]>=d[t.second]+i.second&&s[i.first]>i.second){
				s[i.first]=i.second;
				d[i.first]=d[t.second]+i.second;
				q.push({d[i.first],i.first});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,vv,w;
		cin>>u>>vv>>w;
		v[u].push_back({vv,w});
		v[vv].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		a[i][0]=x;
		for(int j=1;j<=n;j++){
			cin>>x;
			a[i][j]=x;
		}
	}
	int ma=0;
	dijistar(1);
	for(int i=2;i<=n;i++) ma+=s[i];
	cout<<ma;
	return 0;
}
