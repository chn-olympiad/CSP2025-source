#include<bits/stdc++.h>
#define ll long long
#define pll pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+8;
int f[N];
inline int froot(int x){while(f[x]!=x) x=f[x]=f[f[x]];return x;}
struct Edge{
	int u,v,w;
}y[N*10],e[N*10];
inline bool cmp(const Edge &x,const Edge &y){
	return x.w<y.w;
}
int n,m,k;
int v[12],a[12][N];
ll ans;
void work(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>y[i].u>>y[i].v>>y[i].w;
	sort(y+1,y+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int a=froot(y[i].u),b=froot(y[i].v);
		if(a==b) continue;
		cnt++;
		y[cnt]=y[i];
		f[a]=b;
		ans+=y[i].w;
		if(cnt==n-1) break;
	}
	for(int i=0;i<k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int s=1;s<=(1<<k);s++){
		ll sum=0;cnt=n-1;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<n;i++) e[i]=y[i];
		int us=0;
		for(int i=0;i<k;i++){
			if(s&(1<<i)){
				us++;
				sum=sum+v[i];
				for(int j=1;j<=n;j++){
					e[++cnt]={i+n+1,j,a[i][j]};
				}
			}
		}
		if(sum>ans) continue;
		sort(e+1,e+cnt+1,cmp);
		int ce=0;
		for(int i=1;i<=cnt;i++){
			int a=froot(e[i].u),b=froot(e[i].v);
			if(a==b) continue;
			f[a]=b;
			sum+=e[i].w;
			ce++;
			if(sum>=ans) break;
			if(ce==n+us-1) break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int T=1;//cin>>T;
	while(T--){
		work();
	}
	return 0;
}
