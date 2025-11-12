#include<bits/stdc++.h>
using namespace std;
struct edg{
	int u,v,w; 
}e[1000005];
int a[15][10005];
int val[15];
int fa[10005],siz[10005];
bool cmp(edg x,edg y){return x.w<y.w;}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	sort(e+1,e+m+1,cmp);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int dx=find(e[i].u),dy=find(e[i].v);
		if(dx!=dy){
			if(siz[dx]>siz[dy]){
				fa[dy]=dx;
				siz[dx]+=siz[dy];
			}
			else{
				fa[dx]=dy;
				siz[dy]+=siz[dx];
			}
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
	//>=16pts
}
