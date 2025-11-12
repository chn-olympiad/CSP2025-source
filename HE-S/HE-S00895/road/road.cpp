#include"bits/stdc++.h"
using namespace std;
const int maxn = 10020;
const int maxm = 1000020;
const int maxk = 11;
int n,m,k,Ft[1025][maxn],Dp[1025][maxn],c[maxn],Cc[1025],TI;
long long Ans[1025];
struct Edge{int u,v,w,Ty;};
inline bool Cmp(Edge u,Edge v){return u.w<v.w;}
inline int FF(int I,int x){return Ft[I][x]==x?x:Ft[I][x]=FF(I,Ft[I][x]);}
vector<Edge>E;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n>>m>>k;
	int MASK=(1<<k);
	for(int s=0;s<=(1<<k);s++)
		for(int i=1;i<=n+k;i++)
			Ft[s][i]=i;
	for(int i=1;i<=m;i++){
		Edge N;
		cin>>N.u>>N.v>>N.w,N.Ty=0;
		E.push_back(N);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int s=0;s<(1<<k);s++)
			if(s&(1<<(i-1)))
				Ans[s]+=c[i];
		for(int j=1;j<=n;j++){
			Edge N;
			N.u=i+n,N.v=j,cin>>N.w,N.Ty=1;
			E.push_back(N);
		}
	}
	sort(E.begin(),E.end(),Cmp);
	for(auto I:E){
		if(I.Ty==0){
			if(FF(MASK,I.u)==FF(MASK,I.v))continue;
			Ft[MASK][FF(MASK,I.u)]=FF(MASK,I.v);	
		}
		for(int s=0;s<(1<<k);s++){
			if(Cc[s]==n+__builtin_popcount(s)-1)continue;
			if(I.Ty==1&&(s&(1<<(I.u-n-1)))==0)continue;
			int u=FF(s,I.u),v=FF(s,I.v);
			if(u!=v){
				if(Dp[s][u]>Dp[s][v])swap(u,v);
				Ft[s][u]=v,Dp[s][v]+=(Dp[s][u]==Dp[s][v]);
				Ans[s]+=I.w,Cc[s]++;
			}
		}
	}
	long long A=1e18;
	for(int s=0;s<(1<<k);s++)
		A=min(A,Ans[s]);
	cout<<A<<'\n';
}
