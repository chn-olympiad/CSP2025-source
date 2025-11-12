#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+50;
const int maxm=1e6+1e5+10;
int n,m,z,b[15],c[15][maxn],a[15],len,an,cn,fa[maxn],cnt,ans=1e18;
int findf(int x){
	if(fa[x]==x) return x;
	return fa[x]=findf(fa[x]);
}
struct nod{
	int x,y,w;
}s[maxm];
struct node{
	int x,y,w;
}sa[maxm];
bool cmp(node A,node B){
	if(A.x==B.x&&A.w==B.w) return A.y<B.y;
	if(A.w==B.w) return A.x<B.x;
	return A.w<B.w;
}
void kruscal(){
	for(int i=1;i<=n+len;i++) fa[i]=i;
	an=0;
	cn=0;
	for(int i=1;i<=cnt;i++){
		if(findf(sa[i].x)==findf(sa[i].y)) continue;
		fa[findf(sa[i].x)]=findf(sa[i].y);
		cn++;
		an+=sa[i].w;
		if(cn==n+len-1) break;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&z);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&s[i].x,&s[i].y,&s[i].w);
		sa[i].x=s[i].x,sa[i].y=s[i].y,sa[i].w=s[i].w;
	}
	for(int i=1;i<=z;i++){
		scanf("%lld",&b[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
		}
	}
	for(int i=0;i<(1<<z);i++){
		len=0;
		for(int j=0;j<z;j++){
			if((i>>j)&1==1) a[++len]=j+1;
		}
		cnt=m;
		for(int j=1;j<=len;j++){
			for(int k=1;k<=n;k++){
				sa[++cnt].x=a[j]+n;
				sa[cnt].y=k;
				sa[cnt].w=c[a[j]][k];
			}
		}
		sort(sa+1,sa+cnt+1,cmp);
		kruscal();
		for(int j=1;j<=len;j++) an+=b[a[j]];
		ans=min(ans,an);
	}
	cout<<ans;
	return 0;
}
