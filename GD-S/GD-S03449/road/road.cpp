#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10005],f[10005];
long long ans;
struct edge{
	int u,v,w;
};
vector<edge> E;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
struct node{
	int v,w;
};
bool cmp_(node x,node y){
	return x.w<y.w;
}
vector<node>a[10005];
int find(int x){
	return (f[x]==x?x:f[x]=find(f[x]));
}
void kru(){
	int cnt=0;
	for(edge e:E){
		int la=find(e.u),lb=find(e.v);
		if(la!=lb){
			f[lb]=f[la];
			cnt++;
			ans+=e.w;
		}
		if(cnt==n-1)break;
	}
}
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		E.push_back({u,v,w});
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1,v,w;j<=n;++j){
			scanf("%d",&w);
			a[i].push_back({j,w});
		}
		sort(a[i].begin(),a[i].end(),cmp_);
//		cout<<a[i][0].w<<" "<<a[i][1].w<<" "<<c[i]<<"\n";
		E.push_back({a[i][0].v,a[i][1].v,a[i][0].w+a[i][1].w+c[i]});
		E.push_back({a[i][2].v,a[i][1].v,a[i][2].w+a[i][1].w+c[i]});
		E.push_back({a[i][0].v,a[i][2].v,a[i][0].w+a[i][2].w+c[i]});
	}
//	cout<<E.size()<<endl;
	sort(E.begin(),E.end(),cmp);
	kru();
	cout<<ans;
	return 0;
}
