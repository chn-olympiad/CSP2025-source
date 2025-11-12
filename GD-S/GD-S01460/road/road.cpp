#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e4+100,M=2e6+10;
ll n,m,k,u,v,w,c[maxn],a[20][maxn],fa[maxn],cnt,ans,vis[20],flg=1;
struct node{
	ll from,to,w,id;
	friend bool operator<(node x,node y){
		if(x.w+c[x.id]==y.w+c[y.id]){
			return c[x.id]>c[y.id];
		}
		return x.w+c[x.id]<y.w+c[y.id];
	}
}edge[M];
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
	ll fx=find(x),fy=find(y);
	if(fx==fy)return ;
	fa[fx]=y;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n+10;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
//		cin>>u>>v>>w;
		edge[++cnt]=(node){u,v,w,0};
	}for(int i=1;i<=k;i++){
//		cin>>c[i];
		scanf("%lld",&c[i]);
		flg&=(bool)(!c[i]);
		for(int j=1;j<=n;j++){
//			cin>>a[i][j];
			scanf("%lld",&a[i][j]);
			flg&=(bool)(!a[i][j]);
			edge[++cnt]=(node){n+i,j,a[i][j],i};
		}
	}if(flg){
		cout<<0;
		return ;
	}
	stable_sort(edge+1,edge+cnt+1);
	
	ll tmp=0,t=0;
	vis[0]=1;
	for(int i=1;i<=cnt;i++){
		if(t==n-1){
//			cout<<i<<' '<<cnt<<' ';
			break;
		}
		node f=edge[i];
		u=f.from,v=f.to,w=f.w;
		if(find(u)==find(v))continue;
		ll id=f.id;
		if(!vis[id]){
			vis[id]=1;
			ans+=c[id];
			n++;
			if(c[id])c[id]=0,stable_sort(edge+i+1,edge+cnt+1);
			
		}
		
		merge(u,v);
		t++;
//		cout<<n<<' ';
		ans+=w;
	}//cout<<ans;
	printf("%lld",ans);
}
int main(){
//	freopen("road1.in","r",stdin);
//	freopen("out.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
} 
