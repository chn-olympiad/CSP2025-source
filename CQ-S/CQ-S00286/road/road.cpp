#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cerr<<#x<<':'<<x<<endl
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1.2e6+5;
int n,m,k;
int a[12][N];
struct node{
	int u,v,w;
}od[N],nw[N],e[N];
inline bool cmp(node x,node y){
	return x.w<y.w;
}
int f[N],siz[N];
int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
inline void merge(int u,int v){
	if(siz[u]<siz[v]) f[u]=v,siz[v]+=siz[u];
	else f[v]=u,siz[u]+=siz[v];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>od[i].u>>od[i].v>>od[i].w;
	sort(od+1,od+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	int ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	int now=0;
	for(int i=1;i<=m;i++){
		int u=find(od[i].u),v=find(od[i].v);
		if(u==v) continue;
		now++;
		ans+=od[i].w;
		merge(u,v);
		if(now==n-1) break;
	}
	for(int bit=1;bit<(1<<k);bit++){
		int res=0,add=0,tw=0,flag=1;
		for(int i=1;i<=n;i++) a[0][i]=1e18;
		for(int i=1;i<=k;i++){
			if(bit&(1<<(i-1))){
				res+=a[i][0];
				add++;
				for(int j=1;j<=n;j++) nw[++tw]={n+add,j,a[i][j]};
			}
			else if(a[i][0]==0) flag=0;
		}
		if(!flag) continue;
		sort(nw+1,nw+tw+1,cmp);
		int top=0,top1=0,top2=0;
		while(1){
			if(top1==m&&top2==tw) break;
			if(top1==m) e[++top]=nw[++top2];
			else if(top2==tw) e[++top]=od[++top1];
			else{
				if(nw[top2+1].w<od[top1+1].w) e[++top]=nw[++top2];
				else e[++top]=od[++top1];
			}
		}
		for(int i=1;i<=n+add;i++) f[i]=i;
		int now=0;
		for(int i=1;i<=top;i++){
			int u=find(e[i].u),v=find(e[i].v);
			if(u==v) continue;
			now++;
			res+=e[i].w;
			merge(u,v);
			if(now==n+add-1) break;
			if(res>ans) break;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}

