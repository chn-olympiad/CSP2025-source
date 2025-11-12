#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u[1000010],v[1000010],w[1000010];
int c[20],a[20][10010];
bool lt[10010][10010];
bool dt[10010][10010];
int ans=0;

struct Node{
	vector<Node*> next;
	int q;
	int nexts=0;
}road[10010];

bool dfs(Node n,int index,Node md){
	if(n.next.empty()) return false;
	for(int i=0;i<n.next.size();i++){
		if(n.next[i]==&md) return true;
		else dfs(*n.next[i],i,md);
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) {
		road[i].q=i;
		road[i].next.resize(100010);
	}
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		lt[u[i]][v[i]]=lt[v[i]][u[i]]=true;
	} 
	for(int i=0;i<n;k++) {
		cin>>c[i];
		for(int j=0;j<n;j++) cin>>a[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n&&j!=i;j++){
			if(lt[i][j]){
				road[i].next[road[i].nexts++]=&road[j];
				road[j].next[road[j].nexts++]=&road[i];
				if(!dt[i][j]){
					ans+=w[i];	
					dt[i][j]=dt[j][i]=true;
				}
			}else{
				bool islt=false;
				for(int p=0;p<road[i].next.size();p++){
					if(dfs(road[i],p,road[j])){
						islt=true;
						if(!dt[i][j]) {
							ans+=w[i];
							dt[i][j]=dt[j][i]=true;
						}
						continue;
					}else {
						int minI=0;
						for(int k=0;k<n;k++) minI=(c[minI]>c[k]?k:minI);
						if(!dt[i][minI]){
							ans+=(a[minI][i]+a[minI][j]);
							dt[i][minI]=dt[minI][i]=true;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
