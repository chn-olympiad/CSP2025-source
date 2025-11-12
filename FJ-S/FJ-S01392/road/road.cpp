#include<bits/stdc++.h>
using namespace std;
const long long M=1100005,N=10005;
long long n,m,k,s,cnt,ans,c[N],fa[N];
struct Node{
	long long u,v,w;
}a[M];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
long long find(long long x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;cnt=m;
	for(long long i=1;i<=m;++i){
		long long u,v,w;
		cin>>u>>v>>w;
		a[i]={u,v,w};
	}
	for(long long i=1;i<=k;++i){
		long long u;
		cin>>c[0];
		for(long long j=1;j<=n;++j){
			cin>>c[j];
			if(c[j]==0)u=j;
		}
		for(long long j=1;j<=n;++j)if(j!=u)a[++cnt]={u,j,c[j]};
	}
	sort(a+1,a+cnt+1,cmp);
	for(long long i=1;i<=n;++i)fa[i]=i;
	for(long long i=1;i<=cnt;++i){
		long long fu=find(a[i].u),fv=find(a[i].v);
		if(fu==fv)continue;
		fa[fu]=fv;
		ans+=a[i].w;
		if(++s==n-1)break;
	}
	cout<<ans<<"\n";
	return 0;
}

