#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+15,M=1e6+1e5+15;
int n,m,k;
ll ans=0;
int cnt,tot=0;
int fa[N];
struct node{
	int a,b;
	ll w;	
}e[M];
int c[15],f[15];
ll ew[15][N];
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x;
}
int get_f(int x){
	return x==fa[x]?x:fa[x]=get_f(fa[x]);
}
inline bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	int x,y,z;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio();
//	cin.tie(0),cout.tie(0);
//	cin>>n>>m>>k;
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
//		cin>>x>>y>>z;
		x=read(),y=read(),z=read();
		e[i]={x,y,z};
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		int fl=0;
//		cin>>c[i];
		c[i]=read();
		for(int j=1;j<=n;j++){
//			cin>>ew[i][j];
			ew[i][j]=read();
			if(ew[i][j]==0) fl=1;
		}
		if(fl&&!c[i]){
			f[i]=1,tot++;
			for(int j=1;j<=n;j++){
				e[++cnt]={n+i,j,ew[i][j]};
			}
		}
	}
	if(tot==k){
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			x=get_f(e[i].a),y=get_f(e[i].b);
			if(x==y) continue;
			fa[x]=y;ans+=e[i].w;
		}
		cout<<ans;
	}
	return 0;
}
