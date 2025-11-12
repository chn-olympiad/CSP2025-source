#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,fa[N];
int to[2*M],nxt[2*M],h[M],cnt;
long long c[15],a[15][N],val[2*M];
bool vis[N];
void add(int u,int v,long long w){
	to[++cnt]=v; val[cnt]=w; nxt[cnt]=h[u]; h[u]=cnt;
}
struct node{
	int x,y; long long z;
	bool operator<(const node &p)const{
		return z<p.z;
	}
}l[M];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[x]=fa[y];
}
long long Kruskal(int m,int x){
	sort(l+1,l+m+1);
	for(int i=1;i<=n+x;i++) fa[i]=i;
	int tmp=0; long long sum=0;
	for(int i=1;i<=m;i++){
		if(tmp==n+x) return sum;
		int x=l[i].x,y=l[i].y,z=l[i].z;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		tmp++; merge(fx,fy);
		sum+=z;
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l[i].x>>l[i].y>>l[i].z;
		add(l[i].x,l[i].y,l[i].z); add(l[i].y,l[i].x,l[i].z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k<=0) cout<<Kruskal(m,0);
	else{
		bool flg=true;
		for(int i=1;i<=k;i++){
			if(c[i]!=0) flg=false;
			for(int j=1;j<=n;j++){
				if(a[i][j]!=0) flg=false;
			}
		}
		if(flg){
			cout<<0;
			return 0;
		}
		else{
			long long ans=1e18;
			for(int i=0;i<(1<<k);i++){
				int tmp=0; long long sum=0;
				for(int j=1;j<=k;j++){
					if(((i>>(j-1))&1)){
						sum+=c[j];
						for(int ii=1;ii<=n;ii++){
							tmp++;
							l[m+tmp].x=n+tmp; l[m+tmp].y=ii; l[m+tmp].z=a[j][ii];
						}
					}
				}
				sum+=Kruskal(m+tmp,tmp);
				ans=min(ans,sum);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
