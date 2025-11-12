#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+20;
const int M=1e6+20;
struct edge{
	ll u,v,w;
	bool operator <(const edge& a) const{
		return w<a.w;
	};
};
ll n,m,k,f[N],cnt,a[20][N],c[N];
vector<edge> g[N];
edge b[M],tmp[M],tmp1[N];
ll find(ll x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
ll kruskal(){
	ll ans=0;
	sort(b+1,b+1+m);
	for(int i=1;i<=m;i++){
		edge u=b[i];
		ll x=find(u.u),y=find(u.v);
		if(x!=y){
			f[x]=y;
			ans+=u.w;
			tmp[++cnt]=u;
			if(cnt==n-1){
				return ans;
			}
		}
	}
}
int main(){
	freopen("road4.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		b[i].u=u;b[i].v=v;b[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	ll minn=kruskal();
	ll p=0;
	for(int i=1;i<=k;i++){
		p=c[i];
		for(int j=1;j<=n;j++)tmp[cnt+j]={n+i,j,a[i][j]};
		for(int l=1;l<=n+i;l++)f[l]=l;
		sort(tmp+1,tmp+1+cnt+n);
		ll ct=0;
		for(int l=1;l<=n+cnt;l++){
			edge u=tmp[l];
			int x=find(u.u),y=find(u.v);
			if(x!=y){
				f[x]=y;
				p+=u.w;
				tmp1[++ct]=u;
				if(ct==n+i-1)break;
			}
		}
		cout<<i<<" "<<p<<endl;
		if(p<minn){
			minn=p;
			for(int i=1;i<=ct;i++)tmp[i]=tmp1[i];
			cnt=ct;
		}
	}
	cout<<minn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

