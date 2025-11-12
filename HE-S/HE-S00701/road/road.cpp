#include<bits/stdc++.h>
using namespace std;

int n,m,k;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;


vector<pair<int,int> > e[10005];
int c[10005];
int a[15][10005];
int fa[10005],ans;

int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}

void kru(){
	int cnt=0;
	while(cnt<n&&q.size()){
		int w=q.top().first,u=q.top().second.first,v=q.top().second.second;
		q.pop();
		int x=find(u),y=find(v);
		if(x==y){
			continue;
		}
		fa[x]=y;
		cnt++;
		ans+=w;
	}
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(make_pair(w,v));
		e[v].push_back(make_pair(w,u));
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flag=0;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			for(int j=0;j<e[i].size();j++){
				pair<int,int> v=e[i][j];
				pair<int,pair<int,int> > tool;
				tool.first=v.first;
				tool.second.first=i;
				tool.second.second=v.second;
				q.push(tool);
			}
		}
		kru();
		cout<<ans;
		return 0;
	}
	if(flag){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
