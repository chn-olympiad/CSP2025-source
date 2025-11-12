#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct kun{
	int l;
	int z;
};
const int N=1e4+100;
vector<kun> a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	int xxx[k+5]={0};
	int hhh=0;
	for(int i=1;i<=k;i++){
		cin>>xxx[i];
		if(xxx[i]!=0){
			hhh=1;
		}
		for(int j=1;j<=n;j++){
			int nm;
			cin>>nm;
			a[j].push_back({n+i,nm});
			a[n+i].push_back({j,nm});
		}
	}
	int g[n+k+5]={0};
	if(hhh==0){
		
		for(int i=1;i<=k;i++){
			for(int j=0;j<a[n+i].size;j++){
				if(a[n+i][j].w==0){
					for(int qu=0;qu<a[n+i].size;qu++){
						if(qu!=j){
							a[a[n+i][qu].l].push_back({a[n+i][j].l,a[n+i][qu].z});
							a[a[n+i][j].l].push_back({a[n+i][qu].l,a[n+i][qu].z});
							a[n+i][qu]
						}
					}
				}
			}
		}
		
		for(int i=1;i<=k;i++){
			for(int j=0;j<a[n+i].size;j++){
				for(int qu=0;qu<a[n+i].size;qu++){
					if(qu!=j){
						a[a[n+i][j].l].push_back({a[n+i][qu].l,a[n+1][qu].z});
						
					}
				}
				
			}
		}
		
		
		
		
		
		queue<int> que;
		que.front(1);
		for(int )
		return 0;	
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}