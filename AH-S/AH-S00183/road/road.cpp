#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int fa[N];
long long c[15];
struct node {
    int fr,to;
    long long w;	
} edge[N];
int cnt=0;
long long a[15][10005];
void add(int u,int v,long long w) {
    edge[++cnt].fr=u;
    edge[cnt].to=v;
    edge[cnt].w=w; return;
}
int find(int i) {
	if(fa[i]==i) return i;
    return find(fa[i]);	
}
bool cmp(node x,node y) {return x.w<y.w;}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v;
	long long w,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
	    scanf("%d %d %lld",&u,&v,&w);
	    if(u>v) swap(u,v);
	    add(u,v,w);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++) {
	    scanf("%lld",&c[i]);
	    for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	sort(edge+1,edge+cnt+1,cmp);
	int pic=0;
    for(int j=1;j<=cnt;j++) {
	  	int u=edge[j].fr,v=edge[j].to;
	    if(find(u)!=find(v)) {fa[find(u)]=find(v);ans+=edge[j].w;pic++;}
	    if(pic==n-1) break;
	}
	for(int i=1;i<=k;i++) {
		long long pans=c[i];
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<=n;j++) {
		    for(int p=1;p<j;p++) {
			    add(p,j,a[i][j]+a[i][p]);  	
			}
		}
		sort(edge+1,edge+cnt+1,cmp);
		int pic=0;
	    for(int j=1;j<=cnt;j++) {
	    	int u=edge[j].fr,v=edge[j].to;
		    if(find(u)!=find(v)) {fa[find(u)]=find(v);pans+=edge[j].w;pic++;}
		    if(pic==n-1) break;
		}
		cnt-=n*(n-1)/2;
		ans=min(ans,pans);
	}
	cout<<ans;
    return 0;	
}
