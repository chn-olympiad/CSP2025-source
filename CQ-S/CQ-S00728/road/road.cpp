#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=LLONG_MAX;
struct node{
	int b,v;
};
vector<node>a[10015];
int mon[15];
void dfs(int bh,long long num,set<int>s,set<int>cnt){
	if(num>=ans){
		return ;
	}
	if(bh<=n){
		cnt.insert(bh);
	}
	if(cnt.size()==n){
		ans=min(ans,num);
		return ;
	}
	for(int i=0;i<a[bh].size();i++){
		if(s.count(a[bh][i].b)==1){
			set<int>s1=s;
			s1.erase(a[bh][i].b);
			dfs(a[bh][i].b,num+a[bh][i].v+(a[bh][i].b>n?mon[a[bh][i].b-n]:0),s1,cnt);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
    	int x,y,v;
    	cin>>x>>y>>v;
    	a[x].push_back({y,v});
    	a[y].push_back({x,v});
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>mon[i-n];
		for(int j=1;j<=n;j++){
			int v;
			cin>>v;
			a[i].push_back({j,v});
			a[j].push_back({i,v});
		}
	}
	set<int>s,cnt;
	for(int i=2;i<=n+k;i++)s.insert(i);
	dfs(1,0,s,cnt);
	cout<<ans;
}
/*
CSP-S T2 Road
*/
