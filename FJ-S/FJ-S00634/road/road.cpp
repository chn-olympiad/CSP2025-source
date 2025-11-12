#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool flag[20001];
struct node{
	int next,val;
};
vector<node>road[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w; 
		road[u].push_back({v,w});
		road[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		int a[n+1];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		cout<<13;
		for(int j=1;j<=n;j++){
			for(int k1=0;k1<road[j].size();k1++){
				int cnt=c+a[j]+a[road[j][k1].next];
				flag[road[j][k].next]=true;
				if(cnt<road[j][k].val){
					road[j][k].val=cnt;
				}
			}
			for(int l=1;l<=n;l++){
				if(flag[road[j][l].next]){
					int cnt=c+a[j]+a[road[j][l].next];
					road[j].push_back({l,cnt});
				}
				//cout<<666;
			}
		}
	}
	//cout<<endl<<endl;
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<road[i].size();j++){
			//cout<<i<<" to "<<road[i][j].next<<" : "<<road[i][j].val<<endl;
		}
	}*/
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/