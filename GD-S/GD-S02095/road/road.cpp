#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,cnt,e[M*2],h[N],nx[M*2],w[M*2],ans,c[110],k,a[110][N],dis[N];
bool flag,vis[N];
void add(int x,int y,int z){
	cnt++;
	e[cnt]=y;
	w[cnt]=z;
	nx[cnt]=h[x];
	h[x]=cnt;
	return ;
}
//zuixiaoshengchengshumobanti
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,W;i<=m;i++){
		cin>>u>>v>>W;
		add(u,v,W);
		add(v,u,W);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=true;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)flag=true;
		}
	}
	if(!flag&&k){
		cout<<0<<'\n';
		return 0; 
	}
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	for(int i=1;i<=n;i++){
		int minx=1,x=-1;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(dis[j]<minx||x==-1){
				x=j;
				minx=dis[j];
			}
		}
		vis[x]=true;
		ans+=dis[x];
		//cout<<h[x]<<' ';
		for(int j=h[x];j;j=nx[j]){
			int y=e[j],z=w[j];
			dis[y]=min(dis[y],z);
		}
	}
	cout<<ans;
	return 0;
}
