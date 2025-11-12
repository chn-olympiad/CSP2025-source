#include<bits/stdc++.h>
using namespace std;
#define read(r1,r2) freopen(r1,"r",stdin);freopen(r2,"w",stdout);
const int N=1e4+5;
int n,m,k,a[N],fa[N],c[10];
long long ans=0;
struct node{
	int u,v,w;
	bool operator<(const node g) const{
		return w>g.w;
	}
};
priority_queue<node>q;
int getfa(int x){
	if(x==fa[x])return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void Kruscal(){
	int fu,fv;
	for(int i=1;i<=n;i++)fa[i]=i;
	int u,v,w;
	while(!q.empty()){
		u=q.top().u;v=q.top().v;w=q.top().w;
		q.pop();
		fu=getfa(u);fv=getfa(v);
		if(fu==fv)continue;
		ans+=w;
		fa[fu]=fv;
	}
}
int main(){
	read("road.in","road.out")
	cin>>n>>m>>k;int u,v,w,c;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	if(k==0){
		Kruscal();
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				u=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==u)continue;
			q.push({u,i,a[i]});
		}
	}
	Kruscal();
	cout<<ans<<endl;
}

