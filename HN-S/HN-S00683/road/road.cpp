#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int fa[N];
int fand(int x){return fa[x]==x?x:fa[x]=fand(fa[x]);}
struct edge{int u,v,val;}a[3000010];
bool cmp(edge x,edge y){return x.val<y.val;}
void solve(){
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].val;
	sort(a+1,a+n+1,cmp);
	int ttt=0;ll ans=0;
	for(int i=1;i<=m;i++){
		int u=fand(a[i].u),v=fand(a[i].v);
		if(u==v) continue;
		fa[v]=u;
		ans+=a[i].val;
		ttt++;
		if(ttt==n-1) break;
	}
	int nn=n,aaa=0;
	for(int i=1;i<=k;i++){
		int s;cin>>s;
		ll sum=aaa+s;n++;
		for(int j=1;j<=nn;j++){
			int val;cin>>val;
			a[++m]={j,n,val};
		}
		ttt=0;
		for(int j=1;j<=n;j++) fa[j]=j;
		sort(a+1,a+m+1,cmp);
		for(int j=1;j<=m;j++){
			int u=fand(a[j].u),v=fand(a[j].v);
			if(u==v) continue;
			fa[v]=u;
			sum+=a[j].val;
			ttt++;
			if(ttt==n-1) break;
		}
		if(sum<ans)	ans=sum,aaa+=s;
		else --n,m-=nn;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;//cin>>t;
	while(t--) solve();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
