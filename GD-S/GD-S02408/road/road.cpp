#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,M=11;
int n,m,k;
struct info{int u,v,w,col,add;};
int cmp(info x,info y){
	return x.w+x.add<y.w+y.add;
}
vector<info>e;
int c[M],tag[M];
vector<info>e_[M];
//
int fa[N];
void init(){for(int i=1;i<=n;i++)fa[i]=i;}
int find(int x){return (fa[x]==x?x:(fa[x]=find(fa[x])));}
bool isok(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return 1;
	else return 0;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	fa[fx]=fy;
}
void work(){
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w,0,0});
	}
	for(int u=1;u<=k;u++){
		cin>>c[u];
		for(int v=1,cur=1,w;v<=n;v++){
			cin>>w;
			if(u==v)continue;
			if(c[u]==0)e.push_back({u,v,w,0,0});
			else e.push_back({u,v,w,u,(c[u]+cur-1)/cur});
			cur++;
		}
	}
	sort(e.begin(),e.end(),cmp);
	init();
	int ans=0;
	for(info i:e){
		int u=i.u,v=i.v,w=i.w,col=i.col;
		if(!isok(u,v)){
			merge(u,v);
			if(col)tag[col]=1;
			ans+=w;
		}
	}
	for(int i=1;i<=k;i++)ans+=tag[i]*c[i];
	cout<<ans;
}
void clear(){}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int _=1;
	while(_--)work(),clear();
	return 0;
} 
