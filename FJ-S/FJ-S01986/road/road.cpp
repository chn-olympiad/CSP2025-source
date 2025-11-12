#include<bits/stdc++.h>
using namespace std;
struct edge{
	int f,t,d;
}e[1000005];
long long n,m,k,c[15],a[15][10005],fa[10005],use[1000005],ans,jian[15],tmp;
bool cmp(edge x,edge y){
	return x.d<y.d;
}
int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].f>>e[i].t>>e[i].d;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(e[i].f),y=find(e[i].t);
		if(x!=y){
			if(y>x) swap(x,y);
			fa[x]=y;
			use[++tmp]=i;
			ans+=e[i].d;
		}
	}
	for(int i=1;i<=k;i++){
		int z=ans+c[i];
		for(int j=1;j<=tmp;j++){
			int x=e[use[j]].f,y=e[use[j]].t,co=e[use[j]].d;
			if(a[i][x]+a[i][y]<co) z-=co,z+=a[i][x]+a[i][y];
		}
		if(z<ans) ans=z;
	}
	cout<<ans;
	return 0;
}
