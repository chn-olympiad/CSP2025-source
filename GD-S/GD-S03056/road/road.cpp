#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10030,maxm=1000006,maxk=12,maxs=(1<<10)+528;
const int inf=1e9+1121;
const ll lnf=1e15+38;
int n,m,k,nd;
struct EDGE{
	int u,v,w;
	bool operator <(const EDGE &qyy)const{return w<qyy.w;}
}E[maxm],A[maxk][maxn];int tt;
int C[maxk];
namespace DSU{
	int f[maxn],N;
	void Dinit(){iota(f+1,f+1+N,1);}
	int fd(int x){return (x==f[x])?x:(f[x]=fd(f[x]));}
	inline bool merge(int u,int v){u=fd(u),v=fd(v);if(u==v) return 0;return f[v]=u,1;}
}using namespace DSU;
void Ikru(){
	sort(E+1,E+1+m);Dinit();nd=n-1;
	for(int i=1,jiw=0;i<=m&&jiw<nd;i++){
		if(!merge(E[i].u,E[i].v)) continue;
		A[0][++jiw]=E[i];
	}A[0][n]={0,0,inf};
}
bool juun[maxk];int liz[maxk];
ll Kru(){
	Dinit();
	int jiw=0;ll res=0;nd=n-2;
	for(int i=0;i<=k;i++){if(juun[i]) nd++,res+=C[i],liz[i]=1;}
	while(jiw<nd){
		int id=0,W=inf;
		for(int i=0;i<=k;i++) if(juun[i]&&(liz[i]<n)&&(A[i][liz[i]].w<W)) id=i,W=A[i][liz[i]].w;
		if(merge(A[id][liz[id]].u,A[id][liz[id]].v)) jiw++,res+=W;
		liz[id]++;
	}return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;N=n+k;
	for(int i=1;i<=m;i++) cin>>E[i].u>>E[i].v>>E[i].w;
	Ikru();
	for(int i=1,val;i<=k;i++){
		cin>>C[i];
		for(int j=1;j<=n;j++){cin>>val;A[i][j]=(EDGE){n+i,j,val};}
		sort(A[i]+1,A[i]+1+n);
	}
	ll ans=lnf;
	const int state=(1<<k);
	for(int s=0;s<state;s++){
		juun[0]=1;for(int i=1;i<=k;i++) juun[i]=((s>>(i-1))&1);
		ans=min(ans,Kru());
	}
	cout<<ans<<'\n';
	return 0;
}
/*
枚举哪些城市进行改造？
对于每个乡镇在内部将边排好序然后插入。 
*/
//15:51 Fin.
