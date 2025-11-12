#include<bits/stdc++.h>
#define int long long
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
const int M=2e6+10,N=2e4+10,inf=1e17;
int n,m,k,c[15],a[15][N],f[N],ans,dp[15][15],maxn;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &a)const{
		return w<a.w;
	}
}e[M],ed[15][N];
vector<int> cs;
int find(int x){
	return (x==f[x])?x:(f[x]=find(f[x]));
}
void kkk(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		ed[0][++cnt]=e[i];
		ans+=e[i].w;
		f[u]=v;
		if(cnt==n-1){
			break;
		}
	}
}
int kk(int num){
	int cnt=0,sum=0;
	int ct[15]={0};
	for(int i:cs)ct[i]=1;
	while(1){
		int mini=0,minn=2e9;
		for(int i:cs){
			if(ct[i]<=n&&ed[i][ct[i]].w<minn){
				minn=ed[i][ct[i]].w,mini=i;
			}
		}
		int i=mini;
		int u=find(ed[i][ct[i]].u),v=find(ed[i][ct[i]].v);
		ct[i]++;
		if(u==v)continue;
		f[u]=v;
		sum+=ed[i][ct[i]-1].w;
		cnt++;
		
		if(cnt==n+num-1){
			return sum;
		}
		if(sum>=ans)return inf;
	}
}
signed main(){
	qwq;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1);
	kkk();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			ed[i][j]={n+i,j,a[i][j]};
		}
		sort(ed[i]+1,ed[i]+n+1);
//		for(int j=1;j<=n;j++){
//			cout<<ed[i][j].u<<"->"<<ed[i][j].v<<": "<<ed[i][j].w<<"\n";
//		}
	}
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++)f[j]=j;
		cs.clear();
		cs.emplace_back(0);
		int sum=0,num=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1)cs.emplace_back(j+1),sum+=c[j+1],num++;
		}
		if(sum>ans)continue;
		
		int tt=kk(num);
//		cout<<sum<<" + ";
//		cout<<tt<<"\n";
		ans=min(ans,sum+tt);
	}
	cout<<ans;
	return 0;
}
/*
sub 1~4   最小生成树 
O((2^k)*n)

*/
