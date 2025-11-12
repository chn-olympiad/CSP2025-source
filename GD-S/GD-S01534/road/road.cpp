#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long u,v,w;
}E[2000005];
long long n,m,k,a[15][10005],c[15],fa[10005];
bool flag=true;
vector<vector<pair<long long,long long>> > e(10005);
long long find(int x){ return fa[x]=(x==fa[x]?x:find(fa[x])); }
bool cmp(edge x,edge y){ return x.w<y.w; }
long long kruskal(){
	sort(E+1,E+1+m,cmp);
	long long ans=0,cnt=0;
	for(long long i=1;i<=n;i++)fa[i]=i;
	for(long long i=1;i<=m;i++){
		long long k1=E[i].u,k2=E[i].v,k3=E[i].w,f1=find(k1),f2=find(k2);
		if(f1!=f2){
			fa[f1]=f2;
			ans+=k3,cnt++;
		}
		if(cnt==n-1)break;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back(make_pair(v,w));
		E[i]=(edge){u,v,w};
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		flag&=c[i]==0;
		for(long long j=1;j<=n;j++)cin>>a[i][j];
	}
	if(flag){
		for(long long i=1;i<=k;i++){
			int pos=-1;
			for(long long j=1;j<=n;j++){
				if(a[i][j]==0)pos=j;
			}
			for(long long j=1;j<=n;j++){
				if(pos!=j)E[++m]=(edge){pos,j,a[i][j]};
			}
		}
		k=0;
	}
	cout<<kruskal();
}
