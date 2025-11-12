#include <bits/stdc++.h>
using namespace std;
bool vis[110005];
long long n,m,m2,k,fa[110005],siz[110005],a[15][110005],c[15],ans=1e18;
struct str{
	long long l,r,p;
} p[1000005],p2[200005];
bool cmp(str x,str y){
	return x.p<y.p;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(siz[x]>siz[y]) swap(x,y);
	if(x!=y) fa[x]=y,siz[y]+=siz[x];
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0);
    cout.tie(0); 
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);  
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1,vis[i]=0;
    for(int i=1;i<=m;i++) cin>>p[i].l>>p[i].r>>p[i].p;
    for(int i=1;i<=k;i++){
    	cin>>c[i];
    	for(int j=1;j<=n;j++) cin>>a[i][j],p2[++m2]={n+i,j,a[i][j]};
	}
    sort(p+1,p+m+1,cmp);
    for(int i=1;i<=m;i++) if(find(p[i].l)!=find(p[i].r)) merge(p[i].l,p[i].r),p2[++m2]=p[i];
	sort(p2+1,p2+m2+1,cmp);
	for(int i=0;i<(1<<k);i++){
		long long sum=0;
		for(int j=1;j<=n+k;j++) fa[j]=j,siz[j]=1,vis[j]=0;
		for(int j=1;j<=k;j++) if(i&(1<<(j-1))) vis[j]=1,sum+=c[j];
		for(int j=1;j<=m2;j++) if((p2[j].l<=n || vis[p2[j].l-n]) && find(p2[j].l)!=find(p2[j].r)) merge(p2[j].l,p2[j].r),sum+=p2[j].p;
		ans=min(ans,sum); 
	} 
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
