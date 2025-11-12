#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define fst first
#define snd second
using namespace std;
const int N=1e4+1,M=2e6+1,K=11;
int n,m,k,tot,w,a[K][N],c[K],f[N+K],sz[N+K];
set<pair<int,pr>>v,s;
pair<int,pr>tmp[M];
ll ans,res,sum;
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
inline bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	if(sz[x]>sz[y])swap(x,y);
	return f[x]=y,sz[y]+=sz[x];
}
inline void sol(){
	tot=res=0;
	for(auto&i:v)tmp[++tot]=i;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1,j=1;i<w;i++,j++){
		while(!merge(tmp[j].snd.fst,tmp[j].snd.snd))j++;
		res+=tmp[j].fst;
	}
	ans=min(ans,res+sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k,w=n;
	for(int i=1,x,y,w;i<=m;i++)cin>>x>>y>>w,v.insert(make_pair(w,make_pair(x,y)));
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	for(auto&i:v)tmp[++tot]=i;
	for(int i=1,j=1;i<w;i++,j++){
		while(!merge(tmp[j].snd.fst,tmp[j].snd.snd))j++;
		res+=tmp[j].fst,s.insert(tmp[j]);
	}
	ans=res;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<1<<k;i++){
		v=s;
		for(int i=1;i<=n+k;i++)f[i]=i,sz[i]=1;
		for(int T=1;T<=k;T++)if(i>>(T-1)&1){
			for(int u=1;u<=n;u++)v.insert(make_pair(a[T][u],make_pair(n+T,u)));
			sum+=c[T],w++;
		}sol();
		for(int T=1;T<=k;T++)if(i>>(T-1)&1)sum-=c[T],w--;
	}
	cout<<ans;
	return 0;
}
/*
Maybe sooner or later, I can fall in love with one leaf
Then in anther future, I'll be able to love someone
*/
