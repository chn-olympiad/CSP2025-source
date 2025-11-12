#include<bits/stdc++.h>
#define int long long
#define popcnt __builtin_popcount
using namespace std;
const int maxn=10050;
const int maxm=1000010;
int n,m,msz,k,tt;
int ans=0x3f3f3f3f3f3f3f3f;
int fa[maxn];
struct node{
	int u,v;
	int w;
}e[maxm],t[1050][maxn];
int c[15][maxn];
//Ë«Ö¸ÕëºÏ²¢×´Ì¬ 
bool cmp(node x,node y){
	return x.w<y.w;
}
int Find(int x){
	if(x==fa[x])return x;
	return fa[x]=Find(fa[x]);
}
void Union(int x,int y){
	x=Find(x),y=Find(y);
	if(x!=y)fa[y]=x;
}
void build(int p,int o){//kruscal
	for(int i=1;i<=10030;i++)fa[i]=i;
	int sum=o;
	int cnt=0;
	for(int i=1;i<=msz;i++){
		if(Find(e[i].u)==Find(e[i].v))continue;
		Union(e[i].u,e[i].v);
		++cnt;
		sum+=e[i].w;
		t[p][cnt]=e[i];
		if(cnt>=n+tt-1)break;
	}
	ans=min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	msz=m;
	build(0,0);
	for(int i=1;i<=k;i++)
	for(int j=0;j<=n;j++)
	cin>>c[i][j];
	
	for(int sta=1;sta<(1<<k);sta++){
		tt=0;
		int o=0;
		int tmp=sta;
		int r=0;
		for(int i=1;i<=k;i++){
			if(tmp&1)o+=c[i][0],r=i,++tt;
			tmp>>=1;
		}
		int lbt=(sta&(-sta));
		int tmp2=lbt^sta;
		int tot=0;
		if(tt!=1){
			int p1=1,p2=1;
			while(p1<=n&&p2<=n+tt-2){
				
				if(t[lbt][p1].w<t[tmp2][p2].w)e[++tot]=t[lbt][p1++];
				else e[++tot]=t[tmp2][p2++];
			}
			while(p1<=n)e[++tot]=t[lbt][p1++];
			while(p2<=n+tt-2)e[++tot]=t[tmp2][p2++];
		}
		else{
			for(int i=1;i<=n;i++)e[++tot]={r+n,i,c[r][i]};
			for(int i=1;i<n;i++)e[++tot]=t[tmp2][i];
			sort(e+1,e+tot+1,cmp);
		}
		msz=tot;
		build(sta,o);
	}
	cout<<ans;
	return 0;
}
