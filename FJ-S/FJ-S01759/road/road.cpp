#include<bits/stdc++.h>
#define int long long
#define N 10104
#define M 1000006
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
#define gc getchar()

void read(int &n){int l=1,num;char ch;
while(ch=gc,ch>'9'||ch<'0')if(ch=='-')l=-1;
num=ch-'0';while(ch=gc,ch<='9'&&ch>='0')
num=num*10+ch-'0';n=num*l;return;}

int n,m,k,tota,fa[N],tote,s[21][N],c[21],ans,vis[11];
struct Edge{int u,v,w,next;}a[M+N*20],e[2*M];
int head[N];
void add(int u,int v,int w){
e[++tote]={u,v,w,head[u]};head[u]=tote;}

int findfa(int k){return fa[k]==k?k:fa[k]=findfa(fa[k]);}

bool cmp(Edge x,Edge y){return x.w<y.w;}

void dfs(int qq){
	if(k==qq){
		for(int i=1;i<=2;i++){
			int num=0,tt=tota;
			for(int i=1;i<=n+k;i++)fa[i]=i;
			for(int i=1;i<=k;i++){
				if(vis[i]){
					num+=c[i];
					for(int j=1;j<=n;j++){
						a[++tota]={n+i,j,s[i][j],0};
					}
				}
			}
			sort(a+1,a+tota+1,cmp);
			for(int i=1;i<=tota;i++){
				int uu=findfa(a[i].u),vv=findfa(a[i].v);
				if(uu!=vv){add(a[i].u,a[i].v,a[i].w);num+=a[i].w;fa[uu]=vv;}
			}ans=min(ans,num);tota=tt;
		}
		return;
	}
	for(int i=1;i<=2;i++){
		vis[qq]=i-1;
		dfs(qq+1);
	}
}

signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		int x,y,z;read(x);read(y);read(z);
		a[++tota]={x,y,z,0};
	}
	
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+tota+1,cmp);
	for(int i=1;i<=tota;i++){
		int uu=findfa(a[i].u),vv=findfa(a[i].v);
		if(uu!=vv){add(a[i].u,a[i].v,a[i].w);ans+=a[i].w;fa[uu]=vv;}
	}
	for(int i=1;i<=k;i++){read(c[i]);for(int j=1;j<=n;j++)read(s[i][j]);}
	int flag=1;
	for(int i=1;i<=k;i++){
		if(c[i]!=0)flag=0;
		bool quq=0;for(int j=1;j<=n;j++)if(s[i][j]==0)quq=1;
		flag=flag&quq;
	}
	if(flag){
		for(int i=1;i<=k;i++)vis[i]=1;
		int num=0,tt=tota;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				num+=c[i];
				for(int j=1;j<=n;j++){
					a[++tota]={n+i,j,s[i][j],0};
				}
			}
		}
		sort(a+1,a+tota+1,cmp);
		for(int i=1;i<=tota;i++){
			int uu=findfa(a[i].u),vv=findfa(a[i].v);
			if(uu!=vv){add(a[i].u,a[i].v,a[i].w);num+=a[i].w;fa[uu]=vv;}
		}ans=min(ans,num);tota=tt;
		cout<<ans;return 0;
	}
	if(k)dfs(1);
	cout<<ans;
	return 0;
}


