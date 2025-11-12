#include<bits/stdc++.h>
using namespace std;
const int N=10011;
int mp[N][N],db[N],a[N][N];
long long ans;
int getdb(int x){
	if(db[x]==x) return x;
	else return db[x]=getdb(db[x]);
}
void merge(int x,int y){
	db[getdb(x)]=getdb(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(mp[u][v]==0) mp[u][v]=mp[v][u]=w;
		else mp[u][v]=mp[v][u]=min(mp[u][v],w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int q=1;q<=n;q++){
				if(j==q) break;
				if(mp[j][q]==0) mp[j][q]=mp[q][j]=a[i][0]+a[i][j]+a[i][q];
				else mp[j][q]=mp[q][j]=min(mp[j][q],a[i][0]+a[i][j]+a[i][q]);
			}
		}
	}
	for(int i=1;i<=n;i++) db[i]=i;
	for(int i=1;i<n;i++){
		int u,v,co=0x3f3f3f3f;
		for(int fu=1;fu<=n;fu++){
			for(int fv=1;fv<=n;fv++){
				if(mp[fu][fv]==0) break;
				if(getdb(fu)!=getdb(fv)&&mp[fu][fv]<co){
					co=mp[fu][fv];
					u=fu;
					v=fv;
				}
			}
		}
		ans+=co;
		merge(u,v);
	}
	cout<<ans;
	return 0;
}
