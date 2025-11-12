#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e6+5;
int n,m,k,idx,cnt;
int fa[N],f[N];
bool vis[N];
ll ans=0;
struct node{
	int u,v,w;
}a[N];
int find(int x){
	return (fa[x]==x?x:fa[x] = find(fa[x]) );
}bool cmp(node x,node y){
	return x.w<y.w;
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	idx = m;
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}for(int i=1;i<=k;i++){
		cin >> f[n+i];
		for(int j=1;j<=n;j++){
			cin >> a[++idx].w;
			a[idx].w += f[n+i];
			a[idx].u = i+n,a[idx].v=j;
		}
	}sort(a+1,a+idx,cmp);
	for(int i=1;i<=n+k;i++)fa[i] = i;
	for(int i=1;i<=idx;i++){
		if(cnt==n)break;
		int fx = find(a[i].u),fy = find(a[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			if(a[i].u>n&&vis[a[i].u])ans-=f[a[i].u];
			if(a[i].u<=n&&vis[a[i].u]==0)cnt++;
			if(a[i].v<=n&&vis[a[i].v]==0)cnt++;
			vis[a[i].u] = vis[a[i].v] = 1;
			ans += a[i].w;
			//cout << a[i].u << " "<<a[i].v << " "<<cnt<<" "<<ans<<endl;
		}
	}cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
