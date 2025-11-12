#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+20,M=1e5+20;
struct node{int x,y,w;}e[M*10],b[N],p[M];
int n,m,k,fa[N],len,c[N],a[15][N],lg[1025];
int f[15];
ll res=1e18;
bool cmp(node x,node y){return x.w<y.w;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w),e[i].x+=k,e[i].y+=k;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx==fy) continue;
		fa[fx]=fy;b[++len]=e[i];
	}m=len;len=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=k+1;j<=k+n;j++){
			scanf("%d",&a[i][j]);
			len++;p[len].x=i;p[len].y=j;p[len].w=a[i][j];
		}
	}
	sort(p+1,p+1+len,cmp);
	for(int i=0;i<k;i++) lg[1<<i]=i;
	for(int i=(1<<k)-1;i>=0;i--){
		int x=i,cnt=0;
		memset(f,0,sizeof(f));
		while(x) f[lg[x&-x]+1]=1,x^=x&-x;
		ll ans=0;
		for(int j=1;j<=k;j++) if(f[j]) ans+=c[j];
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1,it=1,fx,fy;j<=m;j++){
			while(it<=len&&p[it].w<b[j].w){
				if(!f[p[it].x]||(p[it].y<=k&&!f[p[it].y])){it++;continue;}
				fx=find(p[it].x),fy=find(p[it].y);
				if(fx^fy) fa[fx]=fy,ans+=p[it].w;
				it++;
			}
			fx=find(b[j].x),fy=find(b[j].y);
			if(fx^fy) fa[fx]=fy,ans+=b[j].w;
		}
		res=min(res,ans);
	}cout<<res;
	return 0;
}
