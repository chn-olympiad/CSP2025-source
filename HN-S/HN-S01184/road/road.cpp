#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
priority_queue<pair<long long,pair<long long,long long> >,vector<pair<long long,pair<long long,long long > > >,greater<pair<long long,pair<long long,long long> > > > q;
vector<pair<long long,long long> > edge[10001];
long long fa[10001];
long long a[100001];
long long finds(long long x){
	if(x!=fa[x])fa[x]=finds(fa[x]);
	return fa[x];
}
long long nn;
long long ss=0;
long long s[100001];
long long has(){
	
	for(long long i=1;i<=nn+1;i++){
		fa[i]=i;
		//cout<<fa[i]<<endl;
	}
	long long sss[100001];
	
	long long cnt=0;
	while(!q.empty()){
		long long w=q.top().first,u=q.top().second.first,v=q.top().second.second;
		q.pop();
		//cout<<u<<' '<<v<<' '<<w<<endl;
		u=finds(u),v=finds(v);
		if(u!=v){
			fa[u]=finds(v);
			
			cnt+=w;
		}
		
	}
	
	//cout<<cnt<<endl;
	return cnt;
}

int main(){ 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	nn=n;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
		q.push({w,{u,v}});
	}
	for(long long i=1;i<=n;i++){
		fa[i]=i;
	}
	
	long long ans=0;
	while(!q.empty()){
		long long w=q.top().first,u=q.top().second.first,v=q.top().second.second;
		q.pop();
		//cout<<u<<' '<<v<<' '<<' ';
		u=finds(u),v=finds(v);
		//cout<<u<<' '<<v<<endl;
		
		if(u!=v){
			fa[u]=v;
			ans+=w;
			
		}
	}
	//cout<<ans<<endl;
	int jj=n+1;
	
	for(long long i=1;i<=k;i++){
		for(long long j=1;j<=n;j++){
			for(long long l=0;l<edge[j].size();l++){
				q.push({edge[j][l].second,{j,edge[j][l].first}});
			}
		}
		
		cin>>s[jj];
		for(long long j=1;j<=n;j++){
			cin>>a[j];
			q.push({a[j],{nn+1,j}});
			q.push({a[j],{j,nn+1}});
		}
		long long h=has()+s[jj]+ss;
		if(h<ans){
			nn++;
			for(long long j=1;j<=n;j++){
				edge[j].push_back({nn,a[j]});
				edge[nn].push_back({j,a[j]});
			}
			ss+=s[jj];
			ans=h;
		}
		
	}
	cout<<ans;
}
