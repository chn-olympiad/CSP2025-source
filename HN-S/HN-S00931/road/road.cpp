#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int M=2e6+10;
const int N=2e4+10; 
struct jgt{
	int y;
	long long v;
};
struct node{
	int to;
	long long v;
	int nxt;
}t[M*2];
int last[N],top;
void add(int x,int y,long long v){
	t[++top]={y,v,last[x]};
	last[x]=top;
}
long long xq[20];
vector<long long> an[20];
vector<jgt> bn[N];
long long js[N],dis[N];
int vis[N];
long long bfs(){
	priority_queue<pair<long long,int> > q;
	q.push({0,1});
	vis[1]=1;
	long long ans=0;
	dis[1]=0;
	while(q.size()){
		pair<long long,int> ceo=q.top();
		q.pop();
		int x=ceo.second;
//		cout<<x<<" v="<<ceo.first<<endl;
		ans+=dis[x];
		for(int i=last[x];i;i=t[i].nxt){
			int to=t[i].to;
			if(dis[to]<=t[i].v) continue;
			dis[to]=t[i].v;
//			cout<<"   "<<to<<" v="<<t[i].v<<endl;
			if(!vis[to]){
				vis[to]=1;
				q.push({-dis[to],to});
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,v;
		cin>>x>>y>>v;
		bn[x].push_back({y,v});
		bn[y].push_back({x,v});
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>xq[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			an[i].push_back(x);
		}
	}
//	cout<<"fsidf"<<endl;
	memset(js,0x3f,sizeof(js));
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) js[j]=min(js[j],an[i][j]+xq[i]) ;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<bn[i].size();j++){
			jgt x=bn[i][j];
			int to=x.y;
			long long v=x.v;
			if(js[to]<v){
				add(i,n+1,js[to]);
				add(n+1,i,js[to]);
				add(n+1,to,js[to]);
				add(to,n+1,js[to]);
			}
			else{
				add(i,to,v);
				add(to,i,v);
			}
		}
	}
//	cout<<"ijfbds"<<endl;
	memset(dis,0x3f,sizeof(dis));
	cout<<bfs();
	return 0;
}
