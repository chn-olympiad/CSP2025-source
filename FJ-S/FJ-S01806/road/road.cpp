#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,uu,vv,ww,c[20],flag[20],fa[N];
struct sb{int u,v,w;}a1[3*N],a2[2*N],a3[2*N];
long long anss=114514191981081;
bool cmp(sb x,sb y){
	return  x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void solve(){
	int tot=0,tot2=0;
	long long ans=0,hk=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		if(flag[i]==1){
			ans+=c[i];
			tot2++;
			fa[i+n]=i+n;
			for(int j=(i-1)*n+1;j<=i*n;j++){
				tot++;
				a3[tot]=a2[j];
			}
		}
		else fa[i+n]=-1;
	}
	sort(a3+1,a3+1+tot,cmp);
	int c1=0,c2=0;
	a1[m+1].w=a3[tot+1].w=998244353;
	int xx,yy;
	for(int i=1;i<=m+tot;i++){
		if(hk==n+tot2-1) break;
		if(a1[c1+1].w<a3[c2+1].w){
			c1++;
			xx=find(a1[c1].u),yy=find(a1[c1].v);
			if(xx!=yy){
				hk++;
				ans+=a1[c1].w;
				fa[xx]=yy;
			}
		}
		else{
			c2++;
			xx=find(a3[c2].u),yy=find(a3[c2].v);
			if(xx!=yy){
				hk++;
				ans+=a3[c2].w;
				fa[xx]=yy;
			}
		}
	}
	anss=min(anss,ans);
}
void work(int x){
	x++;
	if(x==k+1) solve();
	else{
		flag[x]=1;
		work(x);
		flag[x]=0;
		work(x);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a1[i].u,&a1[i].v,&a1[i].w);
	sort(a1+1,a1+1+m,cmp);
	int yw=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&yw);
			a2[(i-1)*n+j].u=i+n,a2[(i-1)*n+j].v=j,a2[(i-1)*n+j].w=yw;
		}
	}
	work(0);
	cout<<anss;
	return 0;
}