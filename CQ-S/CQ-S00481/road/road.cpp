#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,k,f[1000106],g[15],c2[15][10004];
long long ans=LONG_LONG_MAX,c[15][10004];
struct node{
	int u,v;
	long long w;
}a[1000006],b[100005],d[100005];
struct need{
	int id;
	long long p;
}p[10004];
inline int cmp(node x,node y){return x.w<y.w;}
inline int cmp2(need x,need y){return x.p<y.p;}
inline int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]); 
}
inline void init(){
	int head=1,tot=0,opt=n; long long sum=0;
	for(int i=1;i<=n;i++) f[i]=i;
	while(head<=m){
		if(find(a[head].u)==find(a[head].v)) {head++;continue;}
		sum+=a[head].w; f[find(a[head].u)]=find(a[head].v); opt--;
		d[++tot]=a[head]; head++;
		if(opt==1 || sum>=ans) break;
	}
	for(int i=1;i<=tot;i++) a[i]=d[i]; m=tot;
	return ;
}
inline void dfs(int x){
	if(x>k){
		int tot=0,cnt=0,head=1,head2=1,opt;
		long long sum=0;
		for(int i=1;i<=k;i++){
			if(g[i]==0) continue;
			sum+=c[i][0]; cnt++;
			if(sum>=ans) return ;
			for(int j=1;j<=n;j++) b[++tot].u=c2[i][j],b[tot].v=n+cnt,b[tot].w=c[i][j];
		}
		sort(b+1,b+tot+1,cmp); opt=n+cnt;
		for(int i=1;i<=n+cnt;i++) f[i]=i;
		while(head<=m){
			while(head2<=tot && b[head2].w<=a[head].w){
				if(find(b[head2].u)==find(b[head2].v)) {head2++;continue;}
				sum+=b[head2].w; f[find(b[head2].u)]=find(b[head2].v); opt--; head2++;
				if(opt==1 || sum>=ans) break;
			}
			if(opt==1 || sum>=ans) break;
			if(find(a[head].u)==find(a[head].v)) {head++;continue;}
			sum+=a[head].w; f[find(a[head].u)]=find(a[head].v); opt--; head++;
			if(opt==1 || sum>=ans) break;
		}
		ans=min(ans,sum); 
		return ;
	}
	g[x]=1;
	dfs(x+1);
	g[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	init();
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++) cin>>p[j].p,p[j].id=j;
		sort(p+1,p+n+1,cmp2);
		for(int j=1;j<=n;j++) c[i][j]=p[j].p,c2[i][j]=p[j].id;
	}
	dfs(1);
	cout<<ans;
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
