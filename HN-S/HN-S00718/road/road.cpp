#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],b[15][10005],vis[10005][10005],ans;
struct st{
	int u,v,w,t;
};
st a[100005];
bool cmp(st &x,st &y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	int t=0;
	for(int i=1;i<=m;i++){
		if(vis[a[i].u][a[i].v]==0){
			t++;
			ans+=a[i].w;
			vis[a[i].v][a[i].u]=1;
			vis[a[i].u][a[i].v]=1;
			for(int j=1;j<=n;j++){
				if(vis[j][a[i].v]==1){
					vis[j][a[i].u]=1;
					vis[a[i].u][j]=1;
				}
			}
			for(int j=1;j<=n;j++){
				if(vis[j][a[i].u]==1){
					vis[j][a[i].v]=1;
					vis[a[i].v][j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;	
}
