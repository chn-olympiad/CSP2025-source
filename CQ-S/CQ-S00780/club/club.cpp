#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define eb emplace_back
const int N=1e5+10;
int n,a[N][3];
vector<int>b[3];
inline void solve(){
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		int mx=max({a[i][0],a[i][1],a[i][2]});
		ans+=mx;
		if(a[i][0]==mx) b[0].eb(max(a[i][1],a[i][2])-mx);
		else if(a[i][1]==mx) b[1].eb(max(a[i][0],a[i][2])-mx);
		else b[2].eb(max(a[i][1],a[i][0])-mx);
	}
	if(b[0].size()>n/2){
		sort(b[0].begin(),b[0].end());
		while(b[0].size()>n/2) ans+=b[0].back(),b[0].pop_back();
	}
	if(b[1].size()>n/2){
		sort(b[1].begin(),b[1].end());
		while(b[1].size()>n/2) ans+=b[1].back(),b[1].pop_back();
	}
	if(b[2].size()>n/2){
		sort(b[2].begin(),b[2].end());
		while(b[2].size()>n/2) ans+=b[2].back(),b[2].pop_back();
	}
	printf("%lld\n",ans);
	b[0].clear(),b[1].clear(),b[2].clear();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
