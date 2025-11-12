#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],p[15][10005],cnt,fa[10015],mi,st[10005];
long long ans,sum;
struct edge{
	int u,v,w;
	bool operator<(const edge& u)const{
		return w>u.w;
	}
};
priority_queue<edge> q,q1;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long shortest(){
	long long ans=0,cnt=0;
	while(!q.empty()){
		int f1=find(q.top().u),f2=find(q.top().v);
		if(f1!=f2){
			fa[f1]=f2;
			ans+=1ll*q.top().w;
			cnt++;
			q1.push(q.top());
			if(cnt==(n-1)) return ans;
		}
		q.pop();
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i,st[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		q.push({u,v,w});
	}
	ans=shortest();
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		mi=1;
		for(int j=1;j<=n;j++){
			fa[j]=st[j];
			scanf("%d",&p[i][j]);
			if(p[i][j]<p[i][mi]) mi=j;
			q.push({n+i,j,p[i][j]});
		}
		sum+=1ll*(c[i]+p[i][mi]);
		fa[find(mi)]=n+i;
		while(!q1.empty()) q.push(q1.top()),q1.pop();
		long long ans1=shortest()+sum;
		if(ans1>=ans) sum-=1ll*(c[i]+p[i][mi]);
		else ans=ans1,st[mi]=n+i;
	}
	cout<<ans<<endl;
}
