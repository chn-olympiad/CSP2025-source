#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+205,M=1e6+5;
int n,m,k;
struct edge{
	int u,v,w;
	bool operator<(const edge &B)const{return w<B.w;}
}tmp[M],a[13][N],e[N];
int v[12];
int vis[M],f[N],sz[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void init(){
	for(int i=1;i<=n+k;i++)f[i]=i,sz[i]=1;
}
int p[13],l[13];
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>tmp[i].u>>tmp[i].v>>tmp[i].w;
	sort(tmp+1,tmp+1+m);
	int cnt=0;
	ll ans=0;
	init();
	for(int i=1;i<=m;i++){
		int A=find(tmp[i].u),B=find(tmp[i].v);
		if(A!=B)f[A]=B,a[0][++cnt]=tmp[i],ans+=tmp[i].w;
	}a[0][n].w=1e9+5;
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1,v;j<=n;j++){
			cin>>v;
			a[i][j]=(edge){i+n,j,v};
		}
		sort(a[i]+1,a[i]+1+n);
		a[i][n+1].w=1e9+5;
	}
	for(int s=1;s<1<<k;s++){
		init();
		int he=0;l[0]=1;
		ll now=0;
		for(int i=1;i<=k;i++){
			if((1<<i-1)&s){
				p[++he]=i;
				l[he]=1;
				now+=v[i];
			}
		}
		if(now>=ans)continue;
		for(int t=1;t<n+he;t++){
			int z=0,nw=a[0][l[0]].w;
			for(int i=1;i<=he;i++){
				if(nw>a[p[i]][l[i]].w){
					nw=a[p[i]][l[i]].w;
					z=i;
				}
			}
			int A=find(a[p[z]][l[z]].u),B=find(a[p[z]][l[z]].v);
			if(sz[A]>sz[B])swap(A,B);
			f[A]=B;sz[B]+=sz[A];
			now+=nw;
			if(t==n+he-1)break;
			for(int i=0;i<=he;i++){int li=i==0?n-1:n;
				while(l[i]<=li){
					int A=find(a[p[i]][l[i]].u),B=find(a[p[i]][l[i]].v);
					if(A!=B)break;
					l[i]++;
				}
			}
		}
//		cout<<"FSD "<<s<<" "<<now<<endl;
		ans=min(ans,now);
	}
	cout<<ans;
	return 0;
}
