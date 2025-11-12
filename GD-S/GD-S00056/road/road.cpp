#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to;
	long long dis;
	edge(){};
	edge(const int& ta,const long long& tb):to(ta),dis(tb){};
	bool operator<(const edge& t)const{
		return t.dis<dis;
	};
};
struct edge1{
	int to;
	long long dis;
	vector<bool> vis;
	edge1(){};
	edge1(const int& ta,const long long& tb,vector<bool>& v):to(ta),dis(tb),vis(v){};
	bool operator<(const edge1& t)const{
		return t.dis<dis;
	};
};
int n,m,k;
int cj[15];
long long dis[10025];
vector<edge> ma[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int ta,tb,tc;
		scanf("%d%d%d",&ta,&tb,&tc);
		ma[ta].emplace_back(tb,tc);
		ma[tb].emplace_back(ta,tc);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&cj[i]); 
		for(int j=1;j<=n;j++){
			int cij;
			scanf("%d",&cij);
			ma[n+i].emplace_back(j,cij+cj[i]);
			ma[j].emplace_back(n+i,cij+cj[i]);
		}
	}
	priority_queue<edge1> q;
	for(int i=1;i<=n+k;i++){
		if(i==1) continue;
		dis[i]=0x7fffffff;
	}
//	memset(vis,false,sizeof(vis));
	vector<bool> vis(15,0);
	q.emplace(1,0,vis);
	while(!q.empty()){
		edge1 np=q.top();
		q.pop();
		int now=np.to;
		if(dis[np.to]<np.dis) continue;
		for(auto e:ma[now]){
			if(e.to>n&&np.vis[e.to-n]){
				if(dis[now]+e.dis-cj[e.to-n]<dis[e.to]){
					dis[e.to]=dis[now]+e.dis-cj[e.to-n];
					q.emplace(e.to,dis[e.to],np.vis);
				}
			}else
				if(dis[now]+e.dis<dis[e.to]){
					dis[e.to]=dis[now]+e.dis;
					if(e.to>n) np.vis[e.to-n]=1;
					q.emplace(e.to,dis[e.to],np.vis);
				}
		}
	}
	long long ans;
	for(int i=2;i<=n;i++){
		ans+=dis[i];
//		printf("%lld ",dis[i]);
	}
//	puts("");
	printf("%lld",ans);
	return 0;

}

