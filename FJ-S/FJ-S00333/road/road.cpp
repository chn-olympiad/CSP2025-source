#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[1000005];
int f[10005];
int Find(int x){
	if(f[x]=x)return x;
	return f[x]=Find(f[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int ans=0;
int c[15];
int g[15][10005];
int tot=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			if(a[i].w>c[j]+g[j][a[i].u]+g[j][a[i].v]){
				tot++;
				a[m+tot].u=a[i].u;
				a[m+tot].v=a[i].v;
				a[m+tot].w=g[j][a[i].u]+g[j][a[i].v]+c[j];
				
			}
		}
	}
	sort(a+1,a+m+tot+1,cmp);
	int cnt=0;
	for(int i=1;i<=m+tot;i++){
		if(Find(a[i].u)==Find(a[i].v)) continue;
		cnt++;
		f[Find(a[i].u)]=Find(a[i].v);
		ans+=a[i].w;
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

