//
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e4+5,MAXM=1e6+5;

pair<int,pair<int,int> > a[MAXM];
vector<pair<int,pair<int,int> > > b,c;
int dis[15][MAXN],val[15];
int fa[MAXN];
int siz=0;

int fath(int id){
	if (fa[id]==id) return id;
	return fa[id]=fath(fa[id]);
}

void mer(int x,int y){
	fa[fath(x)]=fath(y);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
		scanf("%lld %lld %lld",&a[i].second.first,&a[i].second.second,&a[i].first);
	
	for (int i=1;i<=k;i++){
		scanf("%lld",&val[i]);
		for (int j=1;j<=n;j++)
			scanf("%lld",&dis[i][j]);
	}
	
	sort(a+1,a+1+m);
	
	for (int i=1;i<=m;i++)
		if (fath(a[i].second.first)!=fath(a[i].second.second)){
			b.push_back(a[i]);
			mer(a[i].second.first,a[i].second.second);
		}
	
	int ans=1e18;
	for (int i=0;i<(1<<k);i++){
		int sum=0;
		c.clear();
		for (auto z:b) c.push_back(z);
		for (int j=1;j<=k;j++){
			if ((i>>(j-1))&1){
				sum+=val[j];
				for (int z=1;z<=n;z++) c.push_back({dis[j][z],{z,n+j}});
			}
		}
		for (int j=1;j<=n+k;j++) fa[j]=j;
		sort(c.begin(),c.end());
		for (int j=0;j<c.size();j++)
			if (fath(c[j].second.first)!=fath(c[j].second.second)){
				sum+=c[j].first;
				mer(c[j].second.first,c[j].second.second);
			}
		ans=min(ans,sum);
	}
	printf("%lld",ans);

	return 0;
}

