#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u,v,w;
struct edge{
	long long u,v,w;
	bool operator>(const edge& a)const{return w>a.w;}
};
priority_queue<edge,vector<edge>,greater<edge> > pq; 
long long fa[1145141];
int ans;
long long ask(long long x){
	if(fa[x]==x){
		return x;
	}
	else{
		return fa[x]=ask(fa[x]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		pq.push((edge){u,v,w});
	}
	while(!pq.empty()){
		int x=ask(pq.top().u);
		int y=ask(pq.top().v);
		int qz=pq.top().w;
		pq.pop();
		if(x==y){
			continue;
		}
		fa[x]=y;
		ans+=qz;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/
