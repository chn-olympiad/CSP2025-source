#include<bits/stdc++.h>
using namespace std;
long long n,m,k,mem[10010],ans=99999999999999;
struct B{
	int v;
	int w;
};
vector<B> G[10020];

struct XC{
	int change;
	int a[10010];
}c[20];
bool fin;

void dfs(long long point,long long sum){
	cout<<"第"<<point<<"个点sum为"<<sum<<"\n"; 
//	cout<<"1\n";
	if(fin) return ;
//	if(sum>mem[point]){
////		cout<<"11\n";
//		return ;
//	}
	fin=1;
//	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		if(mem[i]==0){	
			fin=0;
			break;
		}
	}
	if(fin){
		ans=min(ans,sum);
//		cout<<"1\n";
		return ;
	}
	for(int i=0;i<G[point].size();i++){
		if(mem[G[point][i].v]>=sum+G[point][i].w) continue;
		mem[G[point][i].v]=sum+G[point][i].w;
		dfs(G[point][i].v,sum+G[point][i].w);
	}
}

int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(mem,0x3f,sizeof(mem));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	bool is_A=1;
	for(int i=1;i<=k;i++){
		cin>>c[i].change;
		if(c[i].change!=0) is_A=0;
		for(int j=1;j<=n;j++){
			cin>>c[j].a[i];
		}
	}
	if(is_A){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				G[n+i].push_back({j,c[i].a[j]});
			}
		}
//		cout<<G[1].size()<<"\n";
		for(int i=0;i<G[1].size();i++){
			mem[1]=0;
//			cout<<G[1][i].v<<" "<<G[1][i].w<<"\n";
			dfs(G[1][i].v,G[1][i].w);
		}
		cout<<ans;
	}
	else if(k==0){
		for(int i=0;i<G[1].size();i++){
			mem[1]=0;
			dfs(G[1][i].v,G[1][i].w);
		}
		cout<<ans;
	}
	return 0;
} 
