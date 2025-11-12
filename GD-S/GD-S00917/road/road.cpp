#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
struct edge{
	long long u,v,w;
};
edge mp[2000005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
long long fa[100015];
long long findfa(long long n){
	if(fa[n]==n)return n;
	else fa[n]=findfa(fa[n]);
	return fa[n];
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	long long ans=0;
	cin>>n>>m>>k;
	long long num=0;
	for(long long i=1;i<=m;i++){
		num++;
		cin>>mp[num].u>>mp[num].v>>mp[num].w;
	}
	for(long long i=1;i<=k;i++){
		int cj;
		cin>>cj;
		for(long long j=1;j<=n;j++){
			long long aij;
			cin>>aij;
			num++;
			mp[num].u=n+i;
			mp[num].v=j;
			mp[num].w=aij;
		}
	}
	for(long long i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(mp+1,mp+num+1,cmp);
	for(long long i=1;i<=num;i++){
		long long u=mp[i].u;
		long long v=mp[i].v;
		long long w=mp[i].w;
		if(findfa(u)!=findfa(v)){
			fa[findfa(max(u,v))]=min(u,v);
			ans+=w;
		}
	}
	cout<<ans;
}
