#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,nn,mm,k,fa[20005],ans=1e18,sum,cnt,c[15],a[15][10005],vis[15],cnt2;
struct qwe{
	int x,y,z;
}v[3000005],vv[3000005];
inline bool cmp(qwe a,qwe b){
	return a.z < b.z;
}
inline int find(int x){
	if(fa[x]==x) return x;
	return (fa[x] = find(fa[x]));
}
inline void kruskal(){
	for(int i=1;i<=mm;i++) vv[i].x = v[i].x,vv[i].y = v[i].y,vv[i].z = v[i].z;
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=cnt2;i++) fa[vis[i]] = vis[i];
	sort(vv+1,vv+1+mm,cmp);cnt = 0;
	for(int i=1;i<=mm,cnt<nn-1;i++){
		if(sum>ans) return ;
		int x = find(vv[i].x),y = find(vv[i].y);
		if(x!=y){
			fa[x] = fa[y];
			sum += vv[i].z;
			cnt ++ ;
		}
	}
}
inline void dfs(int x){
	if(sum>ans) return ;
	if(x==k+1){
		ll tmp =  sum;
		kruskal();
		ans = min(sum,ans);
		sum = tmp;
		return ;
	}
	dfs(x+1);
	sum += c[x]; 
	for(int i=1;i<=n;i++) 
		v[++mm].x=i,v[mm].y=n+x,v[mm].z=a[x][i];
	vis[++cnt2] = n+x;
	nn++;
	dfs(x+1);
	nn--;
	sum -= c[x];
	mm -= n;	
}
int main(){
 	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k); nn=n;mm=m;
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&v[i].x,&v[i].y,&v[i].z);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	} 
	if(k==0){
		kruskal();
		cout << sum;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
