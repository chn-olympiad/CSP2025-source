#include<bits/stdc++.h>
using namespace std;
struct N{
	int u,v,w;
}a[1000005];
int n,m,k,l[10005],mp[1005][1005],p[15][10005],c[15];
bool cmp(N a,N b){
	if(a.w!=b.w) return a.w<b.w;
	else if(a.u!=b.u) return a.u<b.u;
	return a.v<b.v;
}
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i].u);
			scanf("%d",&a[i].v);
			scanf("%d",&a[i].w);
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=a[i].u;
			while(l[x]) x=l[x];
			int y=a[i].v;
			while(l[y]) y=l[y];
			if(x!=y){
				l[x]=y;
				ans+=a[i].w;
			}
		}
	}
	else{
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d",&u);
			scanf("%d",&v);
			scanf("%d",&w);
			mp[u][v]=mp[v][u]=w;
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++)
				cin>>p[i][j];
			for(int k=1;k<=n;k++){
				for(int j=1;j<=n;j++){
					if(k==j) continue;
					if(mp[k][j]==0) mp[k][j]=mp[j][k]=p[i][k]+c[i]+p[i][j];
					else mp[j][k]=mp[k][j]=min(mp[k][j],p[i][k]+c[i]+p[i][j]);
				}
			}
		}
		int pos=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(mp[j][i]){
					a[++pos].u=j;
					a[pos].v=i;
					a[pos].w=mp[j][i];
				}
			}
		}
		sort(a+1,a+pos+1,cmp);
		for(int i=1;i<=pos;i++){
			int x=a[i].u;
			while(l[x]) x=l[x];
			int y=a[i].v;
			while(l[y]) y=l[y];
			if(x!=y){
				l[x]=y;
				ans+=a[i].w;
			}
		}
	}
	cout<<ans;
	return 0;
} 
