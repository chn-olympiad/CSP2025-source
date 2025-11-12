#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k;
struct Edge{
	int u,v,w;
}edge[M];
int fa[N];
int Find(int x){
	if (fa[x]==x){
		return x;
	}
	return fa[x]=Find(fa[x]);
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
void kruscal(){
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(edge+1,edge+m+1,cmp);
	int cnt=0,sum=0;
	for (int i=1;i<=m;i++){
		int fu=Find(edge[i].u),fv=Find(edge[i].v);
		if (fu!=fv){
			fa[fu]=fv;
			sum+=edge[i].w;
			cnt++;
		}
		if (cnt==n-1){
			break;
		}
	}
	cout<<sum<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if (k==0){
		for (int i=1;i<=m;i++){
			cin>>edge[i].u>>edge[i].v>>edge[i].w;
		}
		kruscal();
	}
	return 0;
}
