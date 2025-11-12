#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
} es[(int)1e6+5];
int c[15];
edge a[15][(int)1e4+5];
int fa[(int)1e4+20];
edge tmp[(1<<10)+5][(int)1e4+20];
int tot[(1<<10)+5];
long long ans;
int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void solve(int now,int lst,int add,long long sum){
	if(now!=0){
		long long res=sum;
		for(int i=1;i<=n+add;i++) fa[i]=i;
		int p1=0,p2=0;
		while(p1<tot[lst]||p2<n){
			if(tot[now]>=n+add-1) break;
			if(p1==tot[lst]||a[add][p2+1].w<tmp[lst][p1+1].w){
				p2++;
				int fax=getfa(a[add][p2].u),fay=getfa(a[add][p2].v);
				if(fax==fay) continue;
				fa[fax]=fay;
				tmp[now][++tot[now]]=a[add][p2];
				res+=a[add][p2].w;
			}else{
				p1++;
				int fax=getfa(tmp[lst][p1].u),fay=getfa(tmp[lst][p1].v);
				if(fax==fay) continue;
				fa[fax]=fay;
				tmp[now][++tot[now]]=tmp[lst][p1];
				res+=tmp[lst][p1].w;
			}
		}
		ans=min(ans,res);
	}
	for(int i=0;i<k;i++){
		if(!((now>>i)&1)&&!tot[now^(1<<i)]) solve(now^(1<<i),now,i+1,sum+c[i+1]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		es[i]=edge{u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j].w,a[i][j].u=n+i,a[i][j].v=j;
	}
	sort(es+1,es+m+1,[](edge a,edge b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(tot[0]>=n-1) break;
		int fax=getfa(es[i].u),fay=getfa(es[i].v);
		if(fax==fay) continue;
		fa[fax]=fay;
		tmp[0][++tot[0]]=es[i];
		ans+=es[i].w;
	}
	for(int i=1;i<=k;i++){
		sort(a[i]+1,a[i]+n+1,[](edge a,edge b){
			return a.w<b.w;
		});
	}
	solve(0,0,0,0);
	cout<<ans;
	return 0;
}

