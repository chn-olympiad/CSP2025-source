#include<bits/stdc++.h>
using namespace std;
int fa[2000001],n,m,k,vis[200001];
long long c[2000001],a[11][20001],ans=0;
struct node{
	long long u,v,z;
}q[2000001],edge[2000001];
int cmp(node a,node b){
	return a.z<b.z;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y){
	fa[x]=y;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&q[i].u,&q[i].v,&q[i].z);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	sort(q+1,q+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fx=find(q[i].u),fy=find(q[i].v);
		if(fx!=fy){
			join(fx,fy);
			ans+=q[i].z;
			edge[++cnt].u=q[i].u;
			edge[cnt].v=q[i].v;
			edge[cnt].z=q[i].z;
			if(cnt==n-1) break;
		}
	}
	for(int i=1;i<=k;i++){
		long long anss=0,flag=0;
		for(int j=1;j<=10001;j++){
			vis[j]=0,fa[j]=j;
		}
//		int cntt=cnt;
		for(int j=1;j<=n;j++){
			edge[++cnt].u=i+n;
			edge[cnt].v=j;
			edge[cnt].z=a[i][j];
		}
		sort(edge+1,edge+cnt+1,cmp);
//		if(i==1) for(int j=1;j<=cntt;j++) cout<<edge[j].u<<" "<<edge[j].v<<" "<<edge[j].z<<'\n';
		for(int j=1;j<=cnt;j++){
			int fx=find(edge[j].u),fy=find(edge[j].v);
			if(fx!=fy){
				anss+=edge[j].z;
				join(fx,fy);
				vis[edge[j].u]++;
				vis[edge[j].v]++; 
				if(fx==i+n||fy==i+n){
					flag=edge[j].z;
				}
//				if(i==1)cout<<fx<<" "<<fy<<'\n';
			}
		}
//		cout<<vis[i+n]<<" ";
		if(vis[i+n]==1||vis[i+n]==0){
			anss-=edge[i].z;
		}
		else anss+=c[i];
		ans=min(ans,anss);
//		cout<<anss;
	}
	printf("%lld",ans); 
} 
