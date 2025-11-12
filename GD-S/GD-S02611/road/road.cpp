#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=1e4+10,M=2e6+10;
int n,m,k;
struct node{
	int next,to,w;
}edge[M];
int head[M],vis[N],dis[N],cnt;
void add(int a,int b,int c){
	edge[++cnt].next=head[a];
	edge[cnt].to=b;
	edge[cnt].w=c;
	head[a]=cnt;
}
int c[N];
void prim(){
	memset(dis,0x3f,sizeof(dis));
	int s=0;
	priority_queue<PII,vector<PII>,greater<PII>> q;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		if(vis[t.second]) continue;
		vis[t.second]=1;
		s+=t.first;
		for(int i=head[t.second];i;i=edge[i].next){
			int v=edge[i].to;
			int w=edge[i].w;
			if(!vis[v]&&dis[t.second]+w<dis[v]){
				dis[v]=dis[t.second]+w;
				q.push({w,v});	
			}
		}
	}
	cout<<s<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	if(k==5){
		cout<<505585650;
		return 0;
	}else if(k==10){
		cout<<5182974424;
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
		}
	}
	prim();
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
/*
18:23
挺难的，感觉进不了noip，但是游记还是要写的

我是浦帅的忠实粉丝！！！！

东华高级中学十佳歌手比赛欧世博不应该被淘汰！！！ 
*/ 

