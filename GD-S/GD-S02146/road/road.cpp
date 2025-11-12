#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,k;
int fa[200107],c[107];
ll a[107][10007],ans;
struct E{
	int x;
	int y;
	int w;
}e[1100007];
bool cmp(E p,E q){
	if(p.w>q.w) return 0;
	return 1;
}
int F(int p){
	if(fa[p]==p) return p;
	fa[p]=F(fa[p]);
	return fa[p];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);//3e6Input!!!
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		ans+=c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&e[m+j+(i-1)*n].w);
			e[m+j+(i-1)*n].x=n+i;
			e[m+j+(i-1)*n].y=j;
		}
	}
	sort(e+1,e+m+n*k+1,cmp);
	for(int i=1;i<=n*k+m;i++){
		int x=e[i].x,y=e[i].y,z=e[i].w;
		if(F(fa[x])==F(fa[y])) continue;
		//cout<<x<<' '<<y<<' '<<z<<endl;
		ans+=z;
		fa[F(x)]=F(fa[y]);
	}
	cout<<ans;
	return 0;
} 
