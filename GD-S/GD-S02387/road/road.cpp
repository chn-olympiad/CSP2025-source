#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+12;
//争取k<=0以及性质A的点 
struct node{
	int u,v,w;
};
int n,m,k,f[N],ans;
vector<node> g;
bool cmp(node x,node y){
	return x.w<y.w;
}
int get(int x){
	if(x==f[x]) return x;
	return f[x]=get(f[x]);
}
void merge(int x,int y){
	int fx=get(x),fy=get(y);
	if(fx!=fy) f[fy]=fx;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int j=1;j<=k;j++){
		int c;
		cin>>c;//c=0
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			g.push_back({n+j,i,a});
		}
	}
	sort(g.begin(),g.end(),cmp);
	for(auto it:g){
		int x=it.u,y=it.v;
		int fx=get(x),fy=get(y);
		if(fx==fy) continue;
		ans+=it.w;
		merge(x,y);
	}
	cout<<ans;
	return 0;
}
