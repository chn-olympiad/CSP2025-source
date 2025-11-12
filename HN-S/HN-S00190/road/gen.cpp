#include<bits/stdc++.h>
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
mt19937_64 rd(time(0));
const int N=1e4,M=1e6,K=10,V=1e9;
void solve(){
	cout<<N<<" "<<M<<" "<<K<<endl;
	for(int i=2;i<=N;i++) cout<<i<<" "<<rd()%(i-1)+1<<" "<<rd()%V<<endl;
	for(int i=1;i<=M-N+1;i++) cout<<rd()%N+1<<" "<<rd()%N+1<<" "<<rd()%V+1<<endl;
	for(int i=1;i<=K;i++,cout<<endl) for(int j=1;j<=N+1;j++) cout<<rd()%V+1<<" ";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}

