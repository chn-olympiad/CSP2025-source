#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5;
struct edge{
	int u,v,w;
	bool operator <(edge b){
		return w<b.w;
	}
};
vector<edge>g,g2;
int n,m,k,a[15][maxn],c[15],f[maxn+15],ans=1e18;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		g.emplace_back((edge){u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	sort(g.begin(),g.end());
	for(int s=0;s<(1<<k);s++){
		for(int i=1;i<=n+k;i++)f[i]=i;
		int res=0;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				res+=c[i];
				for(int j=1;j<=n;j++)g2.emplace_back((edge){n+i,j,a[i][j]});
			}
		}
		sort(g2.begin(),g2.end());
		int curn=__builtin_popcount(s)+n;
		int gs=0,g2s=0,cnt=0;
//		cout<<"s = "<<s<<"\n";
//		cout<<"curn = "<<curn<<"\n"; 
//		cout<<"g2 :\nu\tv\tw\n";
//		for(auto v:g2)cout<<v.u<<" "<<v.v<<" "<<v.w<<"\n";
		while(1){
			int lsw=1e18,rsw=1e18;
			if(gs<g.size())lsw=g[gs].w;
			if(g2s<g2.size())rsw=g2[g2s].w;
			if(lsw==1e18&&rsw==1e18)break;
//			cout<<lsw<<" "<<rsw<<"\n";
			if(lsw<rsw){
				auto now=g[gs];
				int fx=find(now.u),fy=find(now.v);
				if(fx!=fy){
					res+=now.w;
					f[fy]=fx;
					cnt++;
					if(cnt==curn-1)break;
				}
				gs++;
			}
			else{
				auto now=g2[g2s];
				int fx=find(now.u),fy=find(now.v);
				if(fx!=fy){
					res+=now.w;
					f[fy]=fx;
					cnt++;
					if(cnt==curn-1)break;
				}
				g2s++;
			}
		}
//		cout<<gs<<" "<<g2s<<"\n";
//		cout<<res<<" ";
		ans=min(ans,res);
//		cout<<"\n\n";
	}
	cout<<ans;
}

