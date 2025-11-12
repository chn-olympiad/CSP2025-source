#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,K,ans=100000000000001;
int c[11]; 
int fa[10201],vis[10101];
int find(int x){
	if(fa[x]==x){
		return fa[x];
	}
	return fa[x]=find(fa[x]);
}
pair<int,pair<int,int>> e[1000001]; 
void dfs(int now,int sum){
//	cout<<K<<endl;
	if(now>K){
		for(int i=1;i<=n+K;i++){
			fa[i]=i;
		}
		int kk=0;
		cout<<"?";
		for(int i=1;i<=m;i++){
			if(vis[e[i].second.first]&&vis[e[i].second.second]&&find(e[i].second.first)!=find(e[i].second.second)){
			//	cout<<"lai";
				fa[find(e[i].second.first)]=find(e[i].second.second);
			//	cout<<sum<<endl;
				kk+=e[i].first;
			}
		}
		cout<<"?"<<endl;
		cout<<sum+kk<<endl;
		ans=min(ans,sum+kk);
		return ;
	}
	vis[n+now]=1;
	dfs(now+1,sum+c[now]);
	vis[n+now]=0;
	dfs(now+1,sum);
}
signed main(){
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	int t=K;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={w,{u,v}};
		vis[i]=1;//cout<<K<<endl;
	}
	for(int i=1;i<=n+K;i++){
		fa[i]=i;
	}
	//cout<<t<<"ssd";
	K=t;
	cout<<K<<endl; 
	if(K==0){
		sort(e+1,e+1+m);
		int sum=0;
		for(int i=1;i<=m;i++){
			if(find(e[i].second.first)!=find(e[i].second.second)){
				fa[find(e[i].second.first)]=find(e[i].second.second);
				sum+=e[i].first;
			}
		}	
		cout<<sum<<endl;
		return 0;
	}
	int flagc=0,flagk=0;
	for(int i=1;i<=K;i++){
		cin>>c[i];
		if(c[i])flagc=1;
		for(int j=1;j<=n;j++){
			int kk;
			cin>>kk;
//			if(kk==512){
//				cout<<"?";
//			}
	//		cout<<kk<<endl;
//			if(kk==0){
//		//		cout<<"?";
//			}
			e[++m]={kk,{n+i,j}};
		}
	}sort(e+1,e+1+m);
	if(!flagc){
		int sum=0;
		for(int i=1;i<=m;i++){
			if(find(e[i].second.first)!=find(e[i].second.second)){
				fa[find(e[i].second.first)]=find(e[i].second.second);
				sum+=e[i].first;
			//	cout<<e[i].second.first<<" "<<e[i].second.second<<endl;
				cout<<sum<<endl;
			}
		}	
		cout<<sum<<endl;	
		return 0;	
	}
	else{
		dfs(1,0);
		cout<<ans;
	}
}
