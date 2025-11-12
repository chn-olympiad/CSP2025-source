#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long n,m,k,ans,fa[N],num[N],c;
bool vis[N];
struct node{
	long long u,v,w;
}a[N];
long long Find(long long x){return fa[x]==x ? x : fa[x]=Find(fa[x]);}
void merge(long long x,long long y){fa[Find(x)]=Find(y);}
bool cmp(node A,node B){return A.w<B.w;} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) fa[i]=i;
	for(long long i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(long long i=1;i<=k;i++){
		cin>>c;
		for(long long j=1;j<=n;j++){
			cin>>num[j];
		}
	}
	sort(a+1,a+1+m,cmp);
	for(long long i=1;i<=m;i++){
		if(Find(a[i].u)==Find(a[i].v)) continue;
		merge(a[i].u,a[i].v);
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
