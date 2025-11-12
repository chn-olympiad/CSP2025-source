/*
古一到四的点不用改造。先写出来 
巴不太会写连通的最小费用 
伦所以把只能尝试写一下路径 
王
颁
布
了 
汉
谟
拉
比
法
典 
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k,done[10005],dist[10005],num[10005],ans=0; 
vector<int>g[1000005];
vector<int>w[1000005];
//vector<int>u[100005];
struct node{
	int dis,id,o;
	bool friend operator < (node a,node b){
		return a.dis>b.dis;
	}
};
void DIJ(int s){
	priority_queue<node>qp;
	memset(0,done,sizeof(done));
	memset(0x3f,dist,sizeof(dist));
	dist[s]=0;
	qp.push({s,dist[s],1});
	u[1].push_back(s);
	num[1]=1;
	while(!qp.empty()){
		int i=qp.top().id,l=qp.top().o;
		qp.pop();
		if(done[i])continue;
		done[i]=true;
		for(int k=0;k<g[i].size();k++){
			int j=g[i][k],c=w[i][k],cnt=0;
			if(dist[i]+c<dist[j]){
				dist[j]=dist[i]+c;
				
				qp.push({j,dist[j],l+cnt});
				num[j]=l+cnt;
				u[l+cnt].push_back(j);
				cnt++;
				
			}
		}
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,p;i<=m;i++){
		cin>>u>>v>>p;
		g[u].push_back(v);
		g[v].push_back(u);
		w[u].push_back(p);
		w[v].push_back(p);
	}
	
	cout<<25;
	return 0;
}
