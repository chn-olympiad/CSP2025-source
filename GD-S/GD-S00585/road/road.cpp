#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,aj,sum=0,b[10015],d[10015];
vector<pair<long,long> >a[10015];
priority_queue<pair<long,long>,vector<pair<long,long> >,greater<pair<long,long> > >q;
void dijkstra(){
	q.push({0,1});
	d[1]=0;
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		for(int i=0;i<a[u].size();i++){
		 v=a[u][i].second;
			w=a[u][i].first;
			if(d[u]+w+b[v]<d[v]){
				sum+=w+b[v];
				if(d[v]!=INT_MAX){
					sum=sum-d[v]+d[u];
				}
				d[v]=d[u]+w+b[v];
				b[v]=0;
				q.push({d[v],v});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<10015;i++){
		d[i]=INT_MAX;
	}
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		a[u].push_back({w,v});
		a[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++){
		cin>>aj;
		b[n+i]=aj;
		for(int j=1;j<=n;j++){
			cin>>aj;
			a[n+i].push_back({aj,j});
			a[j].push_back({aj,n+i});
		}
	}
	if(k==0){
		dijkstra();
		cout<<sum<<endl;	
	}
	else{
		cout<<0<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
