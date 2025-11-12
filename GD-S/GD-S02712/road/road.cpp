#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct data1{
	long long v,w;
};
vector<data1>s[100005];
long long fu[105];
bool vis[100005];
long long d[100005],ans[100005];
int fa[100005];
void dij(int x){
	for(int i=1;i<=n+k;i++){
		d[i]=INT_MAX;
		vis[i]=0;
	}
	ans[1]=1;
	d[x]=0;
	d[0]=INT_MAX;
	for(int i=1;i<=n+k;i++){
		int t=0;
		for(int j=1;j<=n+k;j++){
			if(d[j]<d[t]&&vis[j]!=1){
				t=j;
			}
		}
		if(t==0)return ;
		vis[t]=1;
		for(int j=0;j<s[t].size();j++){
			int v=s[t][j].v;
			int w=s[t][j].w+d[t];
			if(d[v]>=w){
				ans[v]=ans[t];
				if(v<=n)ans[v]++;
				d[v]=w;
				fa[v]=t;
				vis[v]=0;
			}
		}
		//cout<<endl;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	long long u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		s[u].push_back({v,w});
		s[v].push_back({u,w});
	}
	for(int i=n+1;i<=k+n;i++){
		scanf("%lld",&fu[i-n]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			s[i].push_back({j,w});
			s[j].push_back({i,w+fu[i-n]});
		}
	}
	dij(1);
	long long sum=INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(ans[i]+ans[j]==n){
				sum=min(sum,d[i]+d[j]);
			}
		}
	}
	cout<<sum;
	return 0;
}
