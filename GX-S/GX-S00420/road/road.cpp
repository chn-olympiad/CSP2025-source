#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+5,N=1e4+5,K=15,inf=1e18;
int n,m,k;
struct Edge{
	int u,v,w;
	bool operator < (const Edge&A)const{
		return w<A.w;
	}
};
vector<Edge> e,te;
int c[K];
int a[K][N];
int f[N];
int ans;
int GetFather(int u){
	if(f[u]==u) return u;
	f[u]=GetFather(f[u]);
	return f[u];
}
int Kruskal(){
	int cnt=n;
	int res=0;
	for(auto temp : e){
		int u=temp.u;
		int v=temp.v;
		int w=temp.w;
		int fu=GetFather(u),fv=GetFather(v);
		if(fu!=fv){
			f[fu]=fv;
			cnt--;
			res+=w;
		}
		if(cnt==1) break;
	}
	return res;
}
void sub1(){
	if(k!=0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				for(int t=1;t<=k;t++){
					e.push_back({i,j,a[t][i]+a[t][j]});
				}
			}
		}
	}
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++) f[i]=i;
	ans=Kruskal();
	cout<<ans;
}
int op[K];
void dfs(int dep){
	if(dep==k){
		e=te;
		int res=0;
		for(int t=1;t<=k;t++){
			if(!op[t]) continue;
			res+=c[t];
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					e.push_back({i,j,a[t][i]+a[t][j]});
		}
		sort(e.begin(),e.end());
		for(int i=1;i<=n;i++) f[i]=i;
		res+=Kruskal();
		ans=min(ans,res);
		return;
	}
	op[dep+1]=1;
	dfs(dep+1);
	op[dep+1]=0;
	dfs(dep+1);
}
void sub2(){
	te=e;
	ans=inf;
	dfs(0);
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	//sort(e.begin(),e.end());
	bool flag=true;
	for(int i=1;i<=k;i++)
		if(c[i]!=0){
			flag=false;
			break;
		}
	if(flag){
		sub1();
	}
	else{
		sub2();
	}
	return 0;
}