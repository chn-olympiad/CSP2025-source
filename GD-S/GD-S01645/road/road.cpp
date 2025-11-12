#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100,M=1e6+100;
int n,m,k,c[15],f[N],a[15][N],tot;
struct edg{
	int u,v,w;
}e[M+15*N];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	f[x]=y;
}
int kus(){
	int ans=0;
	sort(e+1,e+1+m+tot,[](edg x,edg y){
		return x.w<y.w;
	});
	for(int i=1;i<=m+tot;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v))continue;
		ans+=w;
		merge(u,v);
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				for(int j1=1;j1<=n;j1++){
					if(j1!=j){
						e[++tot+m]={j,j1,a[i][j1]+c[i]};
					}
				}
			}
		}
	}
	cout<<kus();
	return 0;
} 
