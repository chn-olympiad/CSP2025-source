#include<bits/stdc++.h>
using namespace std;
int n,m,k,tu,tv,tw,fa[11111],f1,f2,sum;
struct edge{
	int u;
	int v;
	int w;
};
vector<edge>e;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int a){
	if(fa[a]==a)return a;
	return fa[a]=find(fa[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>tu>>tv>>tw;
		e.push_back({tu,tv,tw});
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<n;i++){
		f1=find(e[i].u);
		f2=find(e[i].v);
		if(f1!=f2){
			sum+=e[i].w;
			fa[f1]=f2;
		}
	}
	cout<<sum;
	return 0;
}
