#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505;
const ll MOD = 998244353;
int n,m,tp;
int c[N],s[N];
char tst[N];
bool used[N];
ll ans;
inline ll read(){
	ll x = 0;char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x<<1) + (x<<3) + (c^48);
		c = getchar();
	}
	return x;
}
inline ll work(ll x){
	for(ll i = x - 1; i >= 2; --i){
		x = (x * i) % MOD;
	}
	return x;
}
void dfs(int id,int cnt,int sum,int l,int r){
//	printf("id : %d  cnt : %d  sum : %d  l : %d  r : %d\n",id,cnt,sum,l,r);
	if(cnt >= m){
		ans += work(max(1,n - id));
//		printf("id : %d   ans = %lld\n",id,ans);
		return ;
	}
	if(m - cnt > s[n] - s[id - 1] || l > r){
		return ;
	}
	if(id == n + 1){
		return ;
	}
	for(int i = id; i <= n; ++i){
		if(tst[i] == '1'){
			int ll = l;
			while(ll <= r && used[ll] && c[ll] < sum){
				++ll;
			}
			if(ll <= r){
				used[ll] = true;
				dfs(i + 1,cnt + 1,sum,l + 1,r);
				used[ll] = false;
			}
			else{
//				used[l] = true;
//				dfs(i + 1,cnt,sum + 1,l + 1,r);
//				used[l] = false;
				return ;
			}
		}
		else{
			int ll = l;
			while(ll <= r && used[ll]){
				++ll;
			}
			used[ll] = true;
			dfs(i + 1,cnt,sum + 1,ll + 1,r);
			used[ll] = false;
		}
	}
	
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read();m = read();
	bool SP_A = true;
	for(int i = 1; i <= n; ++i){
		tst[i] = getchar();
		s[i] = s[i - 1] + (tst[i] == '1');
//		printf(" (%c) ",tst[i]);
		if(tst[i] == '0'){
			SP_A = false;
		}
	}
	for(int i = 1; i <= n; ++i){
		c[i] = read();
	}
	sort(c + 1,c + 1 + n);
	for(int i = 1; i <= n; ++i){
		printf("%d ",c[i]);
	}
	if(SP_A){
		printf("%lld",work(n));
		return 0;
	}
//	for(int i = 1; i <= n; ++i){
//		printf("%c ",tst[i]);
//	}
	dfs(1,0,0,1,n);
	printf("%lld",ans);
	return 0;
} 
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
