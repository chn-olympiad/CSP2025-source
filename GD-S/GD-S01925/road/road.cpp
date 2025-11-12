#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define P pair<LL,int>
#define mp make_pair
int Rd(){
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9'){
		x=x*10+(char)(c)-48;
		c=getchar();
	}
	return x;
}
const LL Inf=1e17;
const int N=10015;
const int K=11;
int n,m,k,tim;
bool A=true;
LL ans=Inf,sum;
vector<int> G[N];
vector<LL> w[N];
int len[N],vis[N];
bool add[K];
LL c[K],T[K][N];
priority_queue< P,vector<P>,greater<P> > q;
void ADD(int u){		//u is new
	if(u>n){
		int nu=u-n;
		for(int i=1;i<=n;++i){
			if(vis[i]==tim) continue;
			q.push(mp(T[nu][i],i));
		}
		return ;
	}
	for(int i=0;i<len[u];++i){
		int v=G[u][i];
		if(vis[v]==tim) continue;
		q.push(mp(w[u][i],v));
	}
	for(int j=1;j<=k;++j){
		if(add[j]) continue;
		q.push(mp(T[j][u],n+j));
	} 
}
void check(){
	while(!q.empty()) q.pop(); 
	++tim,sum=0;
	vis[n/2]=tim; ADD(n/2);
	while(!q.empty()){
		P now=q.top(); q.pop();
		int u=now.second;
		if(vis[u]==tim) continue;
		vis[u]=tim; ADD(u);
		sum+=now.first;
	}
	for(int i=1;i<=k;++i){
		if(add[i]) continue;
		sum+=c[i];
	}
	ans=min(ans,sum);
}
void dfs(int pos){
	if(pos>k){
		check();
		return ;
	}
	add[pos]=true;  dfs(pos+1);
	add[pos]=false; dfs(pos+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v; LL wi;
	for(int i=1;i<=m;++i){
		u=Rd(),v=Rd(),wi=Rd();
		++len[u],++len[v];
		G[u].push_back(v);
		w[u].push_back(wi);
		G[v].push_back(u);
		w[v].push_back(wi);
	}
	for(int j=1;j<=k;++j){
		c[j]=Rd();
		if(c[j]>0) A=false;
		for(int i=1;i<=n;++i){
			T[j][i]=Rd();
			if(T[j][i]>0) A=false;
		}
	}
	/*
	for(int i=1;i<=n;++i){
		for(int j=0;j<len[i];++j){
			cout<<i<<' '<<G[i][j]<<' '<<w[i][j]<<'\n';
		}
	}
	*/
	if(A && k>0){
		cout<<0;
		return 0;
	}
	if(k>=9) check();
	else dfs(1);
	cout<<ans;
	return 0;
} 
