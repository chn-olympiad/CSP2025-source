#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*f;
}
struct node{
	int u,v;
	ll l;
};
constexpr int N=1.5e4+5;
bool cmp(node &a,node &b){
	return a.l<b.l;
}
int f[N],d[N],c[15],cmin[15];
int fin(int x){
	if(f[x]!=x)return f[x]=fin(f[x]);
	return x;
}
vector<node> g;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,k,u,v,l;
	cin>>n>>m>>k;
	g.reserve(m+1+k*n);
	for(int i=1;i<=m;i++){
		cin>>u>>v>>l;
		g.push_back({u,v,1ll*l*2});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		cmin[i]=1e9+7;
		for(int j=1;j<=n;j++){
			cin>>l;
			g.push_back({j,n+i,1ll*l*2+c[i]});
			cmin[i]=min(cmin[i],l);
		}
	}
	for(int i=1;i<=n+k+k;i++){
		f[i]=i;
	}
	sort(g.begin(),g.end(),cmp);
	node p;
	__int128 ans=0;
	for(auto &edge:g){
		p=edge;
		int x=fin(p.u),y=fin(p.v);
		if(x!=y){
			d[p.u]++,d[p.v]++;
			ans+=p.l;
//			cout<<p.u<<" "<<p.v<<" "<<p.l<<"?\n";
			f[x]=y;
		}
	}
	for(int i=1;i<=k;i++){
//		cout<<i<<" "<<d[i]<<"\n";
		if(d[i+n]==1){
			ans-=1ll*cmin[i]*2+c[i];
//			cout<<" "<<cmin[i]*2<<" "<<c[i]<<"\n";
		}
	}
	cout<<(ll)(ans/2);
}
/*
2 1 1
1 2 8
1 4 4
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
