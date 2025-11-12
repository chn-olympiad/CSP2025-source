#include<bits/stdc++.h>
#define int long long
using namespace std;
struct fish{
	int u,v,w;
}ve[1000005];
int fa[10005];
int find(int x){
	return(x==fa[x]?x:fa[x]=find(fa[x]));
}
bool cmp(fish x,fish y){
	return x.w<y.w;
}
vector<fish>dp[(1<<10)+5];
int dpans[(1<<10)+5];
int dpcnt[(1<<10)+5];
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	cin>>ve[i].u>>ve[i].v>>ve[i].w;
	sort(ve+1,ve+1+m,cmp);
	int sum=0,ans=0;
	for(int i=1;i<=m&&sum<n-1;i++)
	if(find(ve[i].u)!=find(ve[i].v)){
		dp[0].push_back(ve[i]);
		ans+=ve[i].w;
		fa[find(ve[i].u)]=find(ve[i].v);
		sum++;
	}
	dpans[0]=ans;
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		int mn=1e18,flc;
		vector<int>inp;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			inp.push_back(x);
			if(x<mn)mn=x,flc=j;
		}
//		cout<<mn<<' '<<flc<<'\n';
		c+=mn;
//		cout<<c<<"!\n";
		vector<fish>awa;
		for(int j=0;j<n;j++){
			if(j+1==flc)continue;
			awa.push_back({j+1,flc,inp[j]});
		}
		for(int j=0;j<(1<<i);j++){
			dpans[j|(1<<i)]=dpcnt[j]+c;
			dpcnt[j|(1<<i)]=dpans[j|(1<<i)];
			vector<fish>qwq=dp[j];
			for(int ovo=0;ovo<awa.size();ovo++){
				qwq.push_back(awa[ovo]);
			}
			sort(qwq.begin(),qwq.end(),cmp);
//			for(int ovo=0;ovo<qwq.size();ovo++)
//			if(i==0)
//			cout<<qwq[ovo].u<<' '<<qwq[ovo].v<<' '<<qwq[ovo].w<<'\n';
			for(int ii=1;ii<=n;ii++)fa[ii]=ii;
			int sum=0;
			for(int ii=0;ii<qwq.size()&&sum<n-1;ii++)
			if(find(qwq[ii].u)!=find(qwq[ii].v)){
				dp[j|(1<<i)].push_back(qwq[ii]);
				dpans[j|(1<<i)]+=qwq[ii].w;
				fa[find(qwq[ii].u)]=find(qwq[ii].v);
//				if(i==0)
//				cout<<dpans[j|(1<<i)]<<'\n';
				sum++;
			}
			ans=min(ans,dpans[j|(1<<i)]);
//			if(ans==12)cout<<(j|(1<<i))<<'\n';
		}
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}
/*
Kruskal hacked???
mei fu xi Prim zhe bei zi you le /ll

hao xiang san bu.
%ni sai huai xi guan bao fa le.

mei cha dsu wo shi zhe ge /px

80pts

2^k kn log kn

qwq
*/
