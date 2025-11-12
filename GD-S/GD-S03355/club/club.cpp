#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define lson (now<<1)
#define rson (now<<1|1) 
#define fi first
#define se second
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
typedef std::pair<int,int> pii;
constexpr int MAXN = (int)1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = (int)1e9+7;
inline void IO(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
}
int T,v,n,ans,flag,a[MAXN][3],Sum[MAXN],val[MAXN];
bool cmp(const pii& lhs,const pii& rhs){
	return lhs.fi>rhs.fi;
}
void dfs(int now,int cnt1,int cnt2,int cnt3,int sum){
	if(now>n){
		ans = max(ans,sum);
		return;
	}
	if(sum+Sum[n]-Sum[now-1]<=ans) return;
	if(cnt1<(n>>1)) dfs(now+1,cnt1+1,cnt2,cnt3,sum+a[now][0]);
	if(cnt2<(n>>1)) dfs(now+1,cnt1,cnt2+1,cnt3,sum+a[now][1]);
	if(cnt3<(n>>1)) dfs(now+1,cnt1,cnt2,cnt3+1,sum+a[now][2]);
}
//25 pts
signed main(){
	IO();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans = 0;
		cin>>n;
		FOR(i,1,n+1){
			FOR(j,0,3) cin>>a[i][j];
			Sum[i] = Sum[i-1] + max(max(a[i][0],a[i][1]),a[i][2]);
			val[i-1] = a[i-1][0];
		}
		if(n<=50){
			dfs(1,0,0,0,0);
		}else{
			std::sort(val,val+n);
			FOR(i,0,(n>>1)) ans += val[i]; 
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

