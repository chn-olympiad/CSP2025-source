#include <bits/stdc++.h>
using namespace std;
struct road{int u,v,w;}edge[1200050];
int cost[20],bcj[10020],t[20],in[20];
bool jian[100050];
long long ans=0;
priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int getf(int u){
	if(bcj[u]==u) return u;
	return bcj[u]=getf(bcj[u]);
}
bool cmp(road a,road b){return a.w<b.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//调到死为止 
	//1->5 2
	//5->2 2
	//1->2 3
	//如何防止退化? 
	//预处理： MLE&&TLE(?)
	//dijkstra???
	//GG!
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,k; cin >> n >> m >> k;
	for(int i = 0;i <= n+k;i++) bcj[i]=i;
	for(int i = 1;i <= m;i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		q.push({edge[i].w,i});
	}
	for(int i = 1;i <= k;i++){
		cin >> cost[i];
		for(int j = 1;j <= n;j++){
			int ind=m+(i-1)*n+j;
			cin >> edge[ind].w; edge[ind].u=n+i; edge[ind].v=j;
			q.push({edge[ind].w,ind});
		}
	}int nn=n,cnt=0,test=0;
	while(cnt<nn-1&&!q.empty()){
		int ind=q.top().second; q.pop();
		//cout << "txt: " << edge[ind].u << ' ' << edge[ind].v << ' ' << edge[ind].w << endl;
		if(ind>m){
			int tmp=(ind-m-1)/n+1;
			//cout << t[tmp] << endl;
			if(t[tmp]==0&&(!jian[ind-m])){
				jian[ind-m]=1; edge[ind].w+=cost[tmp];
				q.push({edge[ind].w,ind}); continue;
			}int u=getf(edge[ind].u),v=getf(edge[ind].v);
			if(t[tmp]==0&&jian[ind-m]&&u!=v){
				t[tmp]++; nn++; cnt++; in[tmp]=edge[ind].w;
				ans+=edge[ind].w; bcj[u]=bcj[v];continue;
			}
			if(t[tmp]>0&&u!=v){
				t[tmp]++; cnt++; bcj[u]=bcj[v];
				ans+=edge[ind].w-cost[tmp]*jian[ind-m]; continue;
			}
		}
		else{
			int u=getf(edge[ind].u),v=getf(edge[ind].v);
			if(u!=v){
				ans+=edge[ind].w; bcj[u]=bcj[v]; cnt++; continue;
			}
		}
	}
	int aaaa=0;
	for(int i = 1;i < n;i++){
		for(int j = i+1;j <= n;j++){
			if(getf(i)!=getf(j)) aaaa++;
		}
	}cout << cnt << ' ' << nn << ' ' << aaaa << endl;
	for(int i = 1;i <= k;i++){
		if(t[i]==1) ans-=in[i];
	}cout << ans;
	return 0;
}
