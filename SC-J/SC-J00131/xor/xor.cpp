#include<bits/stdc++.h>
#define LL long long
#define rep(i,k,n) for(LL i=k;i<=n;i++)
#define VI vector<int>
using namespace std;
bool check(VI& visited,int x,int y){
	rep(i,x,y)
		if(visited[i]==1)
			return false;
	return true;}
bool cmp(pair<int,int> a,pair<int,int> b){
	int x1=a.second-a.first,x2=b.second-b.first;
	return x1<x2;}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	LL n,k,ans=1;cin>>n>>k;
	vector<LL> a(n+1);
	rep(i,1,n)cin>>a[i];
	vector<VI> pre(n+1,VI(n+1));
	rep(i,1,n){
		rep(j,i,n){
			LL x=0;
			rep(p,i,j)x=(x^a[p]);
			pre[i][j]=x;}}
	vector<pair<int,int>> t;
	rep(i,1,n){
		rep(j,i,n){
			if(pre[i][j]==k){
				t.push_back({i,j});}}}
	sort(t.begin(),t.end(),cmp);
//	for(auto& c:t)cout<<c.first<<' '<<c.second<<"\n";
	VI visited(n+1,0);
	rep(i,t[0].first,t[0].second)visited[i]=1;
	rep(i,1,t.size()-1){
		if(!check(visited,t[i].first,t[i].second))
			continue;
		rep(j,t[i].first,t[i].second)visited[j]=1;
		ans++;}
	cout<<ans;}