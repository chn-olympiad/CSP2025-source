#include<bits/stdc++.h>
#define LL long long
#define rep(i,k,n) for(LL i=k;i<=n;i++)
#define VI vector<LL>
using namespace std;
LL n,m,k;
bool check(VI visited){
	rep(i,1,n){
		if(!visited[i])
			return false;}
	return true;}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vector<vector<pair<LL,LL>>> C(n+k+1);
	VI valc(n+k+1);
	rep(i,1,m){
		LL u,v,val;cin>>u>>v>>val;
		C[u].push_back({v,val});
		C[v].push_back({u,val});}
	rep(i,m+1,k+m){
		cin>>valc[i];
		rep(j,1,m){
			LL val;cin>>val;
			C[j].push_back({i,val});
			C[i].push_back({j,val});}}
	LL Min=LLONG_MAX,Mpos=-1;
	for(auto& c:C[1]){
		LL Val=c.first>n?c.second+valc[c.first]:c.second;
		if(Val<Min){
			Min=Val,Mpos=c.first;}}
	queue<pair<LL,LL>> q;
	q.push({Mpos,Min});
	VI visited(n+k+1,0);
	visited[1]=1;
	LL ans=Min;
	while(!q.empty()){
		LL pos=q.front().first;
		visited[pos]=1;
		if(check(visited))break;
		q.pop();
		LL MIN=LLONG_MAX,MPOS=-1;
		for(auto& c:C[pos]){
			if(!visited[c.first]){
				LL Val=c.first>n?c.second+valc[c.first]:c.second;
				if(Val<MIN){
					MIN=Val,MPOS=c.first;}}}
		q.push({MPOS,MIN});
		ans+=MIN;}
	cout<<ans;}