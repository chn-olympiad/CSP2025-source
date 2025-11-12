#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) x.begin(), x.end()

#ifdef DEBUG
void DD(){cerr<<endl;}
template<typename A,typename...B>void DD(A a,B...b){cerr<<a<<" ",DD(b...);}
#define debug(x...) cerr<<"["<<#x<<"]: ", DD(x)
#else
#define debug(...) (void)11
#endif
#define int long long
void solve(){
	int n; cin>>n;
	vector<array<int,3>>a(n);
	for(int i=0; i<n; i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	int res=0;
	for(int j=0; j<3; j++){
		int s=0;
		priority_queue<pair<i64,int>>q;
		for(int i=0; i<n; i++) s+=a[i][j];
		for(int i=0; i<n; i++){
			int id=j?0:1,d=a[i][id]-a[i][j];
			for(int k=0; k<3; k++) if(j!=k&&d<a[i][k]-a[i][j]) d=a[i][k]-a[i][j],id=k;
			q.emplace(d,id);
		}
		array<int,3>cnt{}; 
		for(int i=0; i<n/2; i++) s+=q.top().first,cnt[q.top().second]++,q.pop();
		for(int i=0; i<n/2; i++){
			auto [d,id]=q.top(); q.pop();
			if(d>=0&&cnt[id]<n/2) cnt[id]++,s+=d;
		}
		res=max(res,s);
	}
	cout<<res<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int tt; cin>>tt;
	while(tt--) solve();	
	return 0;
} 
/*

*/
