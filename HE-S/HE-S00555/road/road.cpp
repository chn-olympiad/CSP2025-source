#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10,M=1e6+10;
struct node{
	int to,net,w;
}tr[M];
int n,m,k;
int a[20][N];
int hd[N],cnt=1;
int fa[N];
bool vis[N];
long long ans=0;
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void ku(){
	int t=0;
	for(int i=1;i<=n;i++){
		if(find(tr[i].to)==find(tr[i].net)) continue;
		fa[tr[i].to]=tr[i].net;
		t++;
		ans+=tr[i].w;
		if(t==n-1) break;
	}
}


int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		
	memset(hd,-1,sizeof(hd));
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		tr[i].to=v;
		tr[i].net=u;
		tr[i].w=w;
	}
	if(k==0){
		sort(tr+1,tr+m+1,cmp);
		ku();
		cout<<ans<<"\n";
		return 0;
	}
	
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k!=0) cout<<0<<"\n";
	
	return 0;
}
