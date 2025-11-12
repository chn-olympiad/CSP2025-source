#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c<=57&&c>=48){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e4+5,M=1e6+2;
int n,m,xm,k,c[13],d[13][N],f[N],mi[13],ans=1e18;
bool op[N],is[N][13];
struct Ed{
	int u,v,w;
}e[M];
struct Ad{
	int u,v,w;
}xe[N*10];
bool cmp(Ed x,Ed y){return x.w<y.w;}
bool Cmp(Ad x,Ad y){return x.w<y.w;}

int gf(int x){
	if(x==f[x])return f[x];
	return f[x]=gf(f[x]);
}
void sv(int X){
	int res=X;//cout<<X<<endl;
	for(int i=1;i<=n;++i)f[i]=i;
	
	int I=1;
	for(int i=1;i<=m;++i){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(I<=xm&&xe[I].w<=w){
			--i;
			u=xe[I].u;v=xe[I].v;w=xe[I].w;++I;
		}
		int fu=gf(u),fv=gf(v);
		if(fu==fv)continue;
		f[fu]=fv;
		res+=w;
	}
	ans=min(ans,res);
	return;
}
void dfs(int g,int sum){
	if(g==k+1){
		xm=0;
		for(int i=1;i<=k;++i){if(!op[i])continue;
			for(int j=1;j<=n;++j){
				if(j==mi[i])continue;
				xe[++xm]={j,mi[i],d[i][j]};
			}
		}
		sort(xe+1,xe+1+xm,Cmp);
		sv(sum);
		return;
	}
	op[g]=1;
	dfs(g+1,sum+c[g]);
	
	if(c[g]>0){op[g]=0;dfs(g+1,sum);}
	return;
}
void solve(){
	n=read();m=read();k=read();
	for(int i=1,u,v,w;i<=m;++i){
		e[i]={read(),read(),read()};
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;++i){
		c[i]=read();int Mx=1e18;
		for(int j=1;j<=n;++j){
			d[i][j]=read();
			if(d[i][j]<Mx){
				Mx=d[i][j];mi[i]=j;
			}
		}
		c[i]+=Mx;
	}
	dfs(1,0);
	printf("%lld",ans);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ttt=1;while(ttt--)solve();
	return 0;
}
