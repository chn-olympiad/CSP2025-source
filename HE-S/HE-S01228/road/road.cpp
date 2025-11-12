#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e6+100,M=1e5+100,INF=0x3f3f3f3f3f3f3f3f;
int n,m,t,k;
ll sum,ans;
int f[M];
ll a[20][M],c[20];
ll ffmin[20][20][M];
bool vis[N],vi[N];
struct node{
	int u,v;
	ll w;
}tr[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
ll ask(int p,int l,int r){
	ll k=log2(r-l+1);
	return min(ffmin[p][k][l],ffmin[p][k][(r-(1<<k)+1)]);
} 
ll __mi(int p,int x){
	ll res=INF;
	if(x>1)res=min(res,ask(p,1,x-1));
	if(x<n)res=min(res,ask(p,x+1,n));
	return res;
}
ll que(int k){
	if(vi[k])return 0;
	return c[k];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>tr[i].u>>tr[i].v>>tr[i].w;
	}
	bool aaa=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		bool aa=1,A=1;
		if(c[i])aa=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j])A=0;
		}
		if(aa&&A)aaa=1;
	}
	//最小生成树 
	if(aaa){
		cout<<0;
		return 0;
	}
	sort(tr+1,tr+1+m,cmp);
	ll cnt=0,id=0;
	for(int i=1;i<=m;i++){
		if(find(tr[i].u)!=find(tr[i].v)){
			ans+=tr[i].w;
			f[find(tr[i].v)]=find(tr[i].u);
			cnt++;
			id=i;
			vis[i]=1;
		}
		if(cnt==n-1)break;
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	//预处理k个st表
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)ffmin[i][0][j]=a[i][j];
		for(int le=1;le<=25;le++){
			for(int j=1;j+(1ll<<le)-1ll<=n;j++){
				ffmin[i][le][j]=min(ffmin[i][le-1ll][j],ffmin[i][le-1][j+(1<<le-1ll)]);
			}
		}
	}
	//处理乡镇 
	for(int i=1;i<=id;i++){
		if(vis[i]){
			//断u 
			ll mi1=tr[i].w,id1=0;
			for(int j=1;j<=k;j++){
				if(a[j][tr[i].u]+__mi(j,tr[i].u)+que(j)<mi1){
					mi1=a[j][tr[i].u]+__mi(j,tr[i].u)+que(j);
					id1=j;
				}
			}
			//断v
			ll mi2=tr[i].w,id2=0;
			for(int j=1;j<=k;j++){
				if(a[j][tr[i].v]+__mi(j,tr[i].v)+que(j)<mi2){
					mi2=a[j][tr[i].v]+__mi(j,tr[i].v)+que(j);
					id2=j;
				}
			}
			ll mi=INF,idx;
			if(mi1<mi2){
				mi=mi1;idx=id1;
			}
			else mi=mi2,idx=id2;
			if(mi<tr[i].w){
				ans-=tr[i].w;ans+=mi;
				vi[idx]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
