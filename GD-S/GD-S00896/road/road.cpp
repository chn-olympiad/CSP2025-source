#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=2e6+10;
int n,m,k;
struct qp{
	int u,v,w;
}a[M];
vector<int> to[N];
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int c[11],aa[11][N];
bool oka=1;
long long ans=0;
int main(){
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		oka&=c[i]==0;
		for(int o=1;o<=n;o++)
			cin>>aa[i][o];
	}
	if(oka){
		for(int i=1;i<=k;i++)
			for(int o=1;o<=n;o++)
				m++,a[m].u=i,a[m].v=o,a[m].w=aa[i][o];
	}
	sort(a+1,a+m+1,[&](qp q,qp p){
		return q.w<p.w;
	});for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu==fv)continue;
		fa[fu]=fv,cnt++;
		ans+=a[i].w;
		if(cnt==n-1)break;
	}if(oka||k==0){
		cout<<ans<<endl;
		return 0;
	}
	return 0;
} 
