#include<bits/stdc++.h>
#define LL long long
#define rep(i,k,n) for(LL i=k;i<=n;i++)
#define VI vector<int>
using namespace std;
const LL mod=998244353;
int n;LL ans=0;
set<VI> st;
VI path;
bool check(VI& sd,VI a){
	LL sum=0;int maxx=INT_MIN;
	for(auto& c:sd)sum+=a[c],maxx=max(maxx,a[c]);
	if(sum>2*maxx)return true;
	return false;}
void dfs(int start,VI a){
	if(path.size()>=3&&!st.count(path)){
		if(check(path,a)){
			ans=(ans+1)%mod;
			st.insert(path);}}
	rep(i,start,n){
		path.push_back(i);
		dfs(i+1,a);
		path.pop_back();}
	return;}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	VI a(n+1);
	rep(i,1,n)cin>>a[i];
	dfs(1,a);
	cout<<ans%mod;}