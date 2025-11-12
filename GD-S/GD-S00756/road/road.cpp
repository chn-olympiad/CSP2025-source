#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,c[11],a[11][N];
ll ans=1e18,d[11][N];
bool vis[11][N];
struct edge{
	int v,w,next;
}e[M<<1];
struct pii{
	ll f;
	int s,t;
	bool operator < (const pii &p)const{
		return f>p.f;
	}
}; 
int cnt,h[N];
void add(int a,int b,int c){
	e[++cnt]={b,c,h[a]};
	h[a]=cnt;
}
void dj(){
	queue<pii> q;
	q.push({0,1,0});
	d[0][1]=0;
	while(!q.empty()){
		pii t=q.front();
		int u=t.s,ce=t.t;
		q.pop();
		vis[ce][u]=0;
		for(int i=h[u];i;i=e[i].next){
			int j=e[i].v;
			if(d[ce][u]+e[i].w<d[ce][j]){
				d[ce][j]=d[ce][u]+e[i].w;
				if(!vis[ce][j]){
					vis[ce][j]=1;
				q.push({d[ce][j],j,ce});
				}
				
			}
		}
		if(!vis[ce+1][u]){ //大力推行城市化 
			ce++;
			if(ce>k) continue;
			d[ce][u]=d[ce-1][u]+c[ce];
			if(!vis[ce][u]){
				vis[ce][u]=1;
			q.push({d[ce][u],u,ce});
			}
			
			for(int i=1;i<=n;i++){
				if(u==i) continue;
				if(d[ce][u]+a[ce][i]<d[ce][i]){
					d[ce][i]=d[ce][u]+a[ce][i];
					if(!vis[ce][i]){
						vis[ce][i]=1;
					q.push({d[ce][i],i,ce});
					}
					
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0x3f,sizeof d);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c),add(b,a,c);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	dj();
	for(int i=0;i<=k;i++){
		ll ma=-1;
		for(int j=1;j<=n;j++){
//			cout<<d[i][j]<<' ';
			ma=max(ma,d[i][j]);
		}
//		putchar(10);
		ans=min(ans,ma);
	}
	cout<<ans;
	return 0;
}

