#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+5,N=1e4+30;
int n,m,k;
int a[15][N],c[15];
int vis[15];
struct node{
	int u,v;ll w;
}b[M],b2[M];
bool cmp(node x,node y){return x.w<y.w;}
int f[N];
int fd(int x){
	if(f[x]==x) return x;
	return f[x]=fd(f[x]);
}
ll minn=1e18;
int cnt;
void solve(ll ct){
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	ll s=0;
	for(int i=1;i<=cnt;i++){
		int fa=fd(b2[i].u),fb=fd(b2[i].v);
		if(fa!=fb){
			f[fa]=fb;
			s+=b2[i].w;	
		}
	}
	minn=min(minn,s+ct);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>b[i].u>>b[i].v>>b[i].w;
	sort(b+1,b+m+1,cmp);
	int now=0;
	for(int i=1;i<=m;i++){
		int fa=fd(b[i].u),fb=fd(b[i].v);
		if(fa!=fb){
			f[fa]=fb;
			b2[++now]=(node){b[i].u,b[i].v,b[i].w};
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<=now;i++) b[i]=b2[i];
	for(int i=0;i<(1<<k);i++){
		ll sum=0,t=0;
		cnt=now;
		for(int j=1;j<=now;j++)
			b2[j]=b[j];
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				sum+=c[j];t++;
				for(int l=1;l<=n;l++){
					b2[++cnt].u=n+j;
					b2[cnt].v=l;
					b2[cnt].w=a[j][l];
				}
			}
		}
		sort(b2+1,b2+cnt+1,cmp);
		solve(sum);
	}
	cout<<minn;
	return 0;
}
