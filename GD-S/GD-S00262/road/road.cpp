#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
int n,m,k,fa[N],ans;
struct node{
	int x,y,z;
}g[N];
bool cmp(node o,node p){
	return o.z<p.z;
}
int find(int ms){
	if(fa[ms]!=ms){
		return fa[ms]=find(fa[ms]);
	}return ms;
}
void lk(int o,int p){
	fa[find(o)]=fa[find(p)];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	scanf("%d%d%d",n,m,k);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[i]={u,v,w};
	}//4567
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(fa[g[i].x])!=find(fa[g[i].y])){
			lk(g[i].x,g[i].y);
			ans+=g[i].z;
		}
	}
//	printf("%d",ans);
	cout<<ans<<"\n";
	for(int i=1;i<=m;i++){
		cout<<g[i].z<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
