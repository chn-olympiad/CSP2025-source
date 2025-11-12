#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fi first
#define sc second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define mset multiset
#define pq priority_queue
#define ull unsigned long long
#define i128 __int128
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
const int maxn=1e5+10;
int n,a[maxn][3],t[3],id[maxn][3],c[3];
vector<int> vec[3],vec2[3];
void solve(){
	cin>>n;
	for(int i:{0,1,2}) vec[i].clear(),vec2[i].clear(),c[i]=0;
	for(int i=1;i<=n;i++){
		for(int j:{0,1,2}) cin>>a[i][j],id[i][j]=j,t[j]=a[i][j];
		sort(id[i],id[i]+3,[](int x1,int x2){return t[x1]>t[x2];});
		vec[id[i][0]].pb(i);
//		cout<<id[i][0]<<" "<<id[i][1]<<" "<<id[i][2]<<endl;
	}
	pq<pii> q;
	ll res=0;
	for(int i=1;i<=n;i++) res+=a[i][id[i][0]],c[id[i][0]]++;
	if(max({c[0],c[1],c[2]})<=n/2) return cout<<res<<endl,void();
	int rep=max({c[0],c[1],c[2]})-n/2,maxi=0;
	for(int i:{0,1,2}) if(c[i]==max({c[0],c[1],c[2]})) maxi=i;
	for(int x:vec[maxi]) q.push({a[x][id[x][1]]-a[x][id[x][0]],x});
//	cout<<rep<<" "<<q.size()<<endl;
	while(rep--){
		pii p=q.top();
		q.pop();
		c[maxi]--,c[id[p.sc][1]]++,res+=p.fi;
		vec2[id[p.sc][1]].pb(p.sc);
	}
	if(max({c[0],c[1],c[2]})<=n/2) return cout<<res<<endl,void();
	while(q.size()) q.pop();
	rep=max({c[0],c[1],c[2]})-n/2,maxi=0;
	for(int i:{0,1,2}) if(c[i]==max({c[0],c[1],c[2]})) maxi=i;
	for(int x:vec2[maxi]) q.push({a[x][id[x][2]]-a[x][id[x][1]],x});
	while(rep--) res+=q.top().fi,q.pop();
	cout<<res<<endl;
}
int main(){
	FileIO("club");
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
