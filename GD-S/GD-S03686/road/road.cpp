#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,fa[10020],cnt;
int findf(int k){
	if(fa[k]==k)return k;
	return fa[k]=findf(fa[k]);
}
struct A{
	ll u,v,w;
	friend bool operator<(A B,A C){
		return B.w>C.w;
	}
};
priority_queue<A>q;
int c[15][10005],p[15],vis[15];//vis[i]<=1则返还建造费 
ll solve1(){
	ll ans=0;
	while(!q.empty()){
		A k=q.top();
		q.pop();
		if(findf(k.u)!=findf(k.v)){
			fa[findf(k.u)]=fa[findf(k.v)];
			ans+=k.w;
			if(k.u<=n&&k.v<=n)cnt++;
			if(cnt==n-1)break;
		}
	}
	return ans;
}
void solveA(){
	for(int i=1;i<=k;i++){
		for(int l=1;l<=n;l++){
			q.push({i+n,l,c[i][l]});
		}
	}
	cout<<solve1();
}
void solve2(){
	
}
void solve3(){
	
}
int main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	bool jl=0;
	for(int i=1;i<=k;i++){
		for(int l=0;l<=n;l++){
			cin>>c[i][l];
		}
		if(c[i][0]!=0)jl=1;
	}
	if(k==0){
		cout<<solve1();
	}
	else if(!jl){
		solveA();
	}
	else if(n<=1000){
		solve2();
	}
	else solve3();
	return 0;
}
