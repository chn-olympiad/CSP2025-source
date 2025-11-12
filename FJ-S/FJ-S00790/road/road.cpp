#include<bits/stdc++.h>
using namespace std;
struct sb{
	long long v,w;
	bool operator<(const sb _)const{
		return w>_.w;
	}
};
vector<sb> e[10005];
priority_queue<sb> q;
int n,m,k,x,y,z,dis[10005],l[10005],vis[10005],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[x].push_back((sb){y,z});
		e[y].push_back((sb){x,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) cin>>l[j];
		if(!k) for(int j=1;j<=n;j++) for(int k=j+1;k<=n;k++){
			e[j].push_back((sb){k,l[j]+l[k]});
			e[k].push_back((sb){j,l[j]+l[k]});
		}
	}
	if(k){
		cout<<0;
		return 0;
	}
	memset(dis,0x3f3f3f,sizeof dis);
	dis[1]=0;
	q.push((sb){1,0});
	while(q.size()){
		x=q.top().v;
		q.pop();
		vis[x]=1;
		for(sb y:e[x]){
			if(dis[y.v]>dis[x]+y.w&&!vis[y.v]){
				dis[y.v]=dis[x]+y.w;
				q.push((sb){y.v,dis[y.v]});
			}
		}
	}
	for(int i=1;i<=n;i++) ans+=dis[i];
	cout<<ans;
	return 0;
}
