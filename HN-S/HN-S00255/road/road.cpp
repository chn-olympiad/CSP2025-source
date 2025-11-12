#include<bits/stdc++.h>
using namespace std;

vector< pair<int,long long> > e[10010];
long long c[20][10010];

queue<int> q;
long long f[100010];
bool v[1000010];

int n,m,k;

void sp(){
	for(int j=1;j<=n;j++){
		for(int i=1;i<=e[j].size();i++){
			int t=e[j][i].second;
			cout<<t<<' ';
		}
		cout<<'\n';
	}
	
	q.push(1);
	f[1]=0;
	while(q.empty()){
		int x=q.front();
		q.pop();
		
		v[x]=true;
		for(int i=1;i<=e[x].size();i++){
			int t=e[x][i].first;
			if(v[t]){
				f[t]=min(f[t],f[x]+e[x][i].second);
			}else{
				f[t]=f[x]+e[x][i].second;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=f[i];
	}
	cout<<ans;
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
		if(c[i][0]){
			flag=false;
		}else{
			for(int j=1;j<=n;j++){
				for(int l=j;l<=n;l++){
					e[j].push_back({l,c[i][j]+c[i][l]});
					e[l].push_back({j,c[i][j]+c[i][l]});
				}
			}
		}
	}
	if(flag){
		sp();
	}
	cout<<'\n';
	return 0;
}
