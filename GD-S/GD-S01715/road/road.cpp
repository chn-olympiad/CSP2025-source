#include<bits/stdc++.h>
#define ll long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int M=1e6+44,N=1e4+44,K=12;
ll n,m,k,u,v,w,c[(1<<K)],a[N][K],fa[N],ans1[N],cost[(1<<K)],edge_size;
int ans=0,cnt=0;
bool used[K];
struct Edge{
	ll u,v,w;
	bool operator <(const Edge &x)const{return w<x.w ;}
}edge[M],edge2[N];
int find (ll x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int krus(int x){
	int cn=0,edge2_size=0,an=0;
	for(int i=1;i<k;i++){
		if((x&(1<<(k-1)))==(1<<(k-1))){
			an+=c[i],cn--;
			for(int j=1;j<=n;j++)edge2[++edge2_size]=Edge{j,i+n,a[j][i]};
		}
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int l=1,r=1;l<=cnt,r<=edge2_size;){
		Edge x;
		if(edge[l]<edge[r])x=edge[l++];
		else x=edge[r++];
		int fu=find(x.u);
		int fv=find(x.v);
		if(fu==fv)continue;
		fa[fu]=fv;
		an+=x.w;
		if(an>ans)return an;
		if(l+r==cn+n-1)return an;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#if LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	cin>>n>>m>>k;
	bool cha=0;
	for(int i=1;i<=m;i++)cin>>u >>v>>w, edge[++edge_size]=Edge{u,v,w};
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[k];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
		}
	}
	sort(edge+1,edge+1+edge_size);
	for(int i=1;i<=m;i++){
		Edge x=edge[i];
		int fu=find(x.u);
		int fv=find(x.v);
		if(fu==fv)continue;
		fa[fu]=fv;
		edge[++cnt]=x;
		ans1[cnt]=ans1[cnt-1]+edge[cnt].w ;
		cout<<ans1[cnt]<<' ';
	}
	ans=ans1[cnt];
	cout<<ans;
	for(int i=0;i<(1<<k);i++)ans=min(krus(i),ans);
	cout<<ans;
	return 0;
} 
