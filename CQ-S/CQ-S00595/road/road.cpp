#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10005,K=15,M=1000005;
struct node{
	int u,v,w;
	int cid;
}road[M];
int cmoney[K];
int cuse[K];
int cfirst[K];
int fa[N+K];
ll ans=0;
int find(int a){
	if(fa[a]==a){
		return a;
	}
	return fa[a]=find(fa[a]);
}
bool cmp(node a,node b){
	if(a.cid>0 && cuse[a.cid]==0){
		return a.w+cmoney[a.cid]<b.w;
	}
	if(b.cid>0 && cuse[b.cid]==0){
		return a.w<b.w+cmoney[b.cid];
	}
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	//init
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
		road[i].cid=0;
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		cin>>cmoney[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			cnt++;
			road[cnt].u=n+i,road[cnt].v=j,road[cnt].w=w;
			road[cnt].cid=i;
		}
	}
	sort(road+1,road+cnt+1,cmp);
	int city=1;
	for(int i=1;i<=cnt;i++){
		node ne=road[i];
		if(find(ne.u)!=find(ne.v)){
			ans+=ne.w;
			fa[ne.u]=ne.v;
			if(ne.cid>0 && cuse[ne.cid]==0){
				cfirst[ne.cid]=ne.w;
				ans+=cmoney[ne.cid];
				sort(road+i+1,road+cnt+1,cmp);
			}
			if(ne.cid>0){
				cuse[ne.cid]++;
			}
			if(ne.cid==0 || cuse[ne.cid]>1){
				city++;
			}
		}
		if(city==n){
			break;
		}
	}
	for(int i=1;i<=k;i++){
		if(cuse[i]==1){
			ans-=cmoney[i];
			ans-=cfirst[i];
		}
	}
	cout<<ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
