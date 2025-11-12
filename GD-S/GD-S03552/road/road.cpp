#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=10035,MAXM=6e6+MAXN,mod=998244353,inf=0x3f3f3f3f;
typedef pair<int,int> pir;
typedef long long ll;
int k,n,m;
ll c[MAXN],a[15][MAXN];
struct edge{
	int u,v;
	ll w;
	bool operator<(const edge &o) const{
		return w<o.w;
	}
}ed[MAXM];
ll ans=0;
int f[MAXN];
int findf(int x){
	return (f[x]==x)?x:f[x]=findf(f[x]);
}
bool merge(int x,int y){
	x=findf(x),y=findf(y);
	if(x==y)
		return false;
	f[x]=y;
	return true;
}
ll read(){
	ll reans=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))reans=(reans<<1)+(reans<<3)+(ch^48),ch=getchar();
	return reans;
}
void write(ll x){
	if(x<10)return (void)putchar(x^48);
	write(x/10);
	putchar(x%10^48);
}
int Subtask0(){
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(ed+1,ed+m+1);
	for(int i=1;i<=m;i++){
		if(merge(ed[i].u,ed[i].v))
			ans+=ed[i].w;
	}
	write(ans);
	return 0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin.tie(nullptr)->sync_with_stdio(false);
//	cin>>n>>m>>k;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
//		cin>>ed[i].u>>ed[i].v>>ed[i].w;
		ed[i].u=read(),ed[i].v=read(),ed[i].w=read();
	for(int i=1;i<=k;i++){
//		cin>>c[i];
		c[i]=read();
		for(int j=1;j<=n;j++){
//			cin>>a[i][j];
			a[i][j]=read();
			for(int k=1;k<j;k++)
				ed[++m]={k,j,c[i]+a[i][k]+a[i][j]};
		}
	}
	Subtask0();
	return 0;
}

