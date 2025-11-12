#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
template <typename T> inline void read(T &x){
	x = 0;
	LL f = 1;
	char c = getchar();
	for(; !isdigit(c); c=getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c=getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void print(T x){
	if(x < 0) x = -x,putchar('-');
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
inline void sprint(const string s){
	for(auto x : s) putchar(x);
	return;
}
const int N = 1e6 + 11,M = 25;
LL n,k,id;
LL a[N],s[N],dp[N];
struct node{
	LL l,r;
}g[N];
map<LL,vector<LL>> mp;
bool cmp(node x,node y){
	if(x.l < y.l) return 1;
	return 0;
}
class cmp2{
public:
	bool operator ()(const LL x,const LL y){
		if(dp[x] < dp[y]) return 1;
		return 0;
	}
};
priority_queue<LL,vector<LL>,cmp2> pq;
class cmp3{
public:
	bool operator ()(const LL x,const LL y){
		if(g[x].r > g[y].r) return 1;
		return 0;
	}
};
priority_queue<LL,vector<LL>,cmp3> stat;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);read(k);
	for(LL i=1;i<=n;i++) read(a[i]);
	for(LL i=1;i<=n;i++){
		s[i] = s[i - 1] ^ a[i];
		mp[s[i]].emplace_back(i);
	}
	for(LL i=0;i<n;i++){
		LL tar = s[i] ^ k;
		if(mp[tar].empty()) continue;
		auto &x = mp[tar];
		LL pos = lower_bound(x.begin(),x.end(),i + 1) - x.begin();
		if(pos != x.size() && x[pos] >= i + 1){
			g[++ id].l = i + 1;
			g[id].r = x[pos];
		}
	}
	sort(g + 1,g + 1 + id,cmp);
	for(LL i=1;i<=id;i++) dp[i] = 1;
	for(LL i=1;i<=id;i++){
		while(stat.size() && g[stat.top()].r < g[i].l){
			pq.emplace(stat.top());
			stat.pop();
		}
		if(pq.size()){
			dp[i] = dp[pq.top()] + 1;
			stat.emplace(i);
		}else stat.emplace(i);
	}
	LL ans = 0;
	for(LL i=1;i<=id;i++) ans = max(ans,dp[i]);
	print(ans);
	return 0;
}
