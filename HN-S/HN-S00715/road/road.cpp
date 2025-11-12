#include<bits/stdc++.h>
#define pii pair<ll,ll>
#define ll long long
using namespace std;

const int N=1e4+15,M=1e6+5;
ll n,m,k,c[17],ans=1e18;
struct edge{
	ll u,v,w;
}ori[M],cty[17][N];
vector<edge> usd;

int f[N];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void init(){
	for(int i=1;i<=n+k;i++)f[i]=i;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll Kruskal(){ // Damn it
	init();
	ll res=0,cnt=0;
	for(int i=1;i<=m&&cnt<n-1;i++){
		if(find(ori[i].u)!=find(ori[i].v)){
			usd.push_back(ori[i]);
			res+=ori[i].w;
			f[find(ori[i].u)]=find(ori[i].v);
			cnt++;
		}
	}
	return res; 
}
vector<edge> bfo;
ll KruskalSP(int state){
	ll res=0,cc=0;
	bfo.clear();
	for(int i=0;i<n-1;i++)bfo.push_back(usd[i]);
	for(int i=1;i<=k;i++){
		if((state>>i-1)&1){
			for(int j=1;j<=n;j++)if(bfo[n-2].w>cty[i][j].w)bfo.push_back(cty[i][j]);
			res+=c[i];
			cc++;
		}
	}
	sort(bfo.begin(),bfo.end(),cmp);
	init();
	ll cnt=0;
	for(int i=0;i<bfo.size()&&cnt<n-1+cc;i++){
		if(find(bfo[i].u)!=find(bfo[i].v)){
			usd.push_back(bfo[i]);
			res+=bfo[i].w;
			f[find(bfo[i].u)]=find(bfo[i].v);
			cnt++;
		}
	}
	return res;
}

inline void read(ll &x){
	x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+(c^'0');
}
	
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(ll i=1;i<=m;i++){
		read(ori[i].u);read(ori[i].v);read(ori[i].w);
	}
	sort(ori+1,ori+m+1,cmp);
	ans=Kruskal();
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(ll j=1,w;j<=n;j++){
			read(cty[i][j].w);
			cty[i][j].u=i+n,cty[i][j].v=j;
		}
		sort(cty[i]+1,cty[i]+n+1,cmp);
	}
	int s=clock();
	for(int i=1;i<=(1<<k)-1;i++){
		ans=min(ans,KruskalSP(i));
	}
	cout<<ans;//<<'\n'<<clock()-s;
	return 0;
}

// I did it...maybe
// yi qie dou shi ming yun shi zhi meng de xuan ze,El Psy Congroo 
// he yi wei?
