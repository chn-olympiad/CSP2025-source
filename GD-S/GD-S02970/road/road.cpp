#include<bits/stdc++.h>
#define int long long
using namespace std;
bool MB1;
const int N=1e6+10,M=2e6+10;
int n,m,k;
struct node{
	int x,y,w;
}e[M],p[M],q[M];
int fa[N],cnt;
int c[N];
int s[11][N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].x)!=find(e[i].y)){
			fa[find(e[i].x)]=find(e[i].y);
			p[++cnt]=e[i];
		}
	}
}
int num,da=1e18,sum;
int calc(){
	int ans=0;
	for(int i=1;i<=sum;i++) fa[i]=i;
	sort(q+1,q+1+num,cmp);
	for(int i=1;i<=num;i++){
		if(find(q[i].x)!=find(q[i].y)){
			ans+=q[i].w;
			fa[find(q[i].x)]=find(q[i].y);
		}
	}
	for(int i=1;i<=sum;i++) if(find(i)!=find(1)) ans=1e18;
	return ans;
}
bool MB2;
void start(){
	#ifdef GNF
	freopen("1.in","r",stdin);
	#endif
}
void end(){
	cerr<<endl;
	cerr<<fixed<<setprecision(3)<<clock()/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	cerr<<abs(&MB2-&MB1)/1024.0/1024.0<<"MB"<<endl;
}
signed main(){
	froepen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	start();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].w;
	}
	solve();
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>s[i][j];
	}
	for(int S=0;S<(1<<k);S++){
		for(int i=1;i<=cnt;i++) q[i]=p[i];
		num=cnt;
		int d=0;sum=n;
		for(int i=0;i<k;i++){
			if(S&(1<<i)){
				d+=c[i];sum++;
				for(int j=1;j<=n;j++){
					q[++num]={sum,j,s[i][j]};
				}
			}
		}
		//cout<<k<<" "<<calc()<<" "<<d<<endl;
		da=min(da,d+calc());
	}
	cout<<da<<endl;
	end();
}

