#include<bits/stdc++.h>
//#define long long long long
using namespace std;
long long n,m,k;
const long long N=4e4+10,M=3e6+10;
struct node{
	long long u,v,w;
}e[M],e1[M];
bool f[1000000];
long long tot;
vector<pair<long long,long long> >cc;
bool cmp(node x,node y){
	return x.w<y.w;
}
long long c[25],new_edge[25][N];
long long fa[N];
long long find(long long x){
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	return x;
}
bool merge(long long x,long long y){
	long long X=find(x),Y=find(y);
	if(X==Y)return 0;
	else{
		fa[X]=Y;
		return 1;
	}
}
long long ans=0;
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)fa[i]=i;
	for(long long i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(long long i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v))ans+=e[i].w,f[i]=1;
	}
	for(long long i=1;i<=m;i++){
		if(f[i]==1)e[++tot]=e[i];
	}
	m=tot;
	if(k==0){
		cout<<ans<<"\n";
		return 0;
	}
	else{
		tot=m;
		for(long long i=1;i<=k;i++){
			cin>>c[i];
			for(long long j=1;j<=n;j++){
				cin>>new_edge[i][j];
			}
		}
		long long minn=ans;
		for(long long i=1;i<=k;i++){
//			now+=c[i];
			ans=c[i];
			tot=m;
			for(long long j=1;j<=m;j++)e1[j]=e[j];
			for(long long j=1;j<=n+k;j++)fa[j]=j;
			for(long long j=1;j<=n;j++)e1[++tot]={i+n,j,new_edge[i][j]};
			sort(e1+1,e1+tot+1,cmp);
			for(long long j=1;j<=tot;j++){
				if(merge(e1[j].u,e1[j].v))ans+=e1[j].w;
			}
			minn=min(minn,ans);
//			cout<<sum<<"\n";
			cc.push_back({ans,i});
		}
		sort(cc.begin(),cc.end());
		tot=m;
		for(long long now=0,i=0;i<(long long)cc.size();i++){
			long long id=cc[i].second;
			now+=c[id];
			ans=now;
//			for(long long i=1;i<=m;)
			for(long long j=1;j<=n+k;j++)fa[j]=j;
			for(long long j=1;j<=n;j++)e[++tot]={id+n,j,new_edge[id][j]};
			sort(e+1,e+tot+1,cmp);
			for(long long j=1;j<=tot;j++){
				if(merge(e[j].u,e[j].v))ans+=e[j].w;
			}
			minn=min(minn,ans);
		}
		cout<<minn<<"\n";
	}
	return 0;
}

