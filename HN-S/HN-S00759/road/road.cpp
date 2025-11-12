#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
struct node{
	int u,v,w,frm;
	bool operator<(const node&nxt)const{
		return w<nxt.w;
	} 
}a[1000005],b[1005005];
int fa[10015];
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void unionn(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		fa[x]=y;
	}
	return;
}
void Kruscal(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		if(cnt>=n){
			break;
		}
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)!=find(v)){
			cnt++;
			ans+=w;
			unionn(u,v);
		}
	}
	cout<<ans; 
	return;
}
int w[15],W[15][10005];
bool vis[15],op[15];
ll Min=1e18;
void dfs(int step){
	if(step>k){
		for(int i=1;i<=m;i++){
			b[i]=a[i];
		}
		int cnt=m;
		int t=0;
		for(int i=1;i<=k;i++){
			op[i]=0;
			if(vis[i]){
				t++;
				for(int j=1;j<=n;j++){
					cnt++;
					b[cnt].u=n+i,b[cnt].v=j,b[cnt].w=W[i][j],b[cnt].frm=i;
				}
			}
		}
		sort(b+1,b+1+cnt);
		for(int i=1;i<=n+t;i++){
			fa[i]=i;
		}
		int f=0;
		ll ans=0;
		for(int i=1;i<=cnt;i++){
			if(f>=n+t){
				break;
			} 
			int u=b[i].u,v=b[i].v,w=b[i].w,frm=b[i].frm;
			if(find(u)!=find(v)){
				f++;
				ans+=w;
				unionn(u,v);
				op[frm]=1;
			}
		}
		for(int i=1;i<=k;i++){
			if(op[i]){
				ans+=w[i];
			}
		}
		Min=min(Min,ans); 
		
		return;
	} 
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w; 
	}
	sort(a+1,a+1+m);
	if(!k){
		Kruscal();
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			cin>>W[i][j];
		}
	}
	dfs(1);
	cout<<Min;
	return 0;
}
