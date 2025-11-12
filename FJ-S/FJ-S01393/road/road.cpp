#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,m,k,a[10010],f[10010],x[11],ans;
bool b[11];
struct edge{
	int u,v,w,f;
}e[10000010];
int find(int fa){
	if(f[fa]==fa)return fa;
	return f[fa]=find(f[fa]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w,e[i].f=0;
	for(int i=1;i<=k;i++){
		cin>>x[i];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int l=1;l<n;l++)
			for(int r=l+1;r<=n;r++)
				e[++m].u=l,e[m].v=r,e[m].w=a[l]+a[r]+x[i],e[m].f=i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;
		ans+=e[i].w;
		f[fv]=fu;
		if(e[i].f>0){
			if(!b[e[i].f])b[e[i].f]=1;
			else ans-=x[e[i].f];
		}
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num=1;
	//cin>>num;
	while(num--)solve();
	return 0;
}
