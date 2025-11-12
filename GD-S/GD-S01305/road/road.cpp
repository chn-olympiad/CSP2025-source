#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <cstdio>
using namespace std;
vector<pair<int,int> >G[10005];
int a[15][10005],c[15];
long long dis[10055],fians = 0x3f3f3f3f;
struct node{
	long long d;
	int idx;
	friend const operator < (node a,node b){
		return a.d > b.d;
	}
};
priority_queue<node> P;
int n,m,k;
long long prim(int T){
	long long ans = 0;
	memset(dis,0x3f,sizeof(dis));
	node temp;
	temp.d = 0; temp.idx = 1;
	dis[1] = 0;
	P.push(temp);
	while(!P.empty()){
		node curr = P.top();
		P.pop();
		if(curr.d != dis[curr.idx]){
			continue;
		}
		ans += curr.d;
		dis[curr.idx] = 0;
		if(curr.idx <= n){
			for(int i = 0;i < G[curr.idx].size();i++){
				if(G[curr.idx][i].first <= n){
					if(dis[G[curr.idx][i].first] > G[curr.idx][i].second){
						dis[G[curr.idx][i].first] = G[curr.idx][i].second;
						node newnode;
						newnode.d = dis[G[curr.idx][i].first];
						newnode.idx = G[curr.idx][i].first;
						P.push(newnode);
					}
				}
				else if((T>>(G[curr.idx][i].first-n-1))%2){
					if(dis[G[curr.idx][i].first] > G[curr.idx][i].second + c[G[curr.idx][i].first-n]){
						dis[G[curr.idx][i].first] = G[curr.idx][i].second + c[G[curr.idx][i].first-n];
						node newnode;
						newnode.d = dis[G[curr.idx][i].first];
						newnode.idx = G[curr.idx][i].first;
						P.push(newnode);
					}
				}
			}
		}
		else{
			for(int i = 1;i<=n;i++){
				if(dis[i] > a[curr.idx-n][i]){
					dis[i] = a[curr.idx-n][i];
					node newnode;
					newnode.d = dis[i];
					newnode.idx = i;
					P.push(newnode);
				}
			}
		}
	}
	return ans;
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++){
		int fr,to,w;
		scanf("%d %d %d",&fr,&to,&w);
		G[fr].push_back({to,w});
		G[to].push_back({fr,w});
	}
	for(int i = 1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j = 1;j<=n;j++){
			scanf("%d",&a[i][j]);
			G[j].push_back({n+1,a[i][j]});
		}
	}
	for(int i = 0;i<(1<<k);i++){
		long long temp = prim(i);
		fians = min(fians,temp);
	}
	cout<<fians;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

