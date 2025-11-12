#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2005, P1=29, P2=1e9+7;
int n, q, len[N];
ll h1[N], h2[N], ht1[N], ht2[N], base[N];
char s1[N], s2[N], t1[N], t2[N];
bool pre[N], suf[N];
inline ll query1(int l, int r){
	return ((ht1[r]-ht1[l-1]*base[r-l+1]%P2)%P2+P2) % P2;
}
inline ll query2(int l, int r){
	return ((ht2[r]-ht2[l-1]*base[r-l+1]%P2)%P2+P2) % P2;
}
inline void solve(){//匹配一组t1,t2 
	int siz = strlen(t1+1);
	ll res = 0;
	for(int i=1; i<=siz; ++i){
		ht1[i] = (ht1[i-1]*P1%P2+t1[i]-64)%P2;
		ht2[i] = (ht2[i-1]*P1%P2+t2[i]-64)%P2;
	}
	pre[0] = suf[siz+1] = true;//预处理前缀和后缀是否相等 
	for(int i=1; i<=siz; ++i)
		pre[i] = pre[i-1]&&(t1[i]==t2[i]);
	for(int i=siz; i; --i)
		suf[i] = suf[i+1]&&(t1[i]==t2[i]);

	for(int i=siz; i; --i){
		if(!suf[i+1]) break;
		for(int j=1; j<=n; ++j){
			if(len[j]<=i && pre[i-len[j]] && query1(i-len[j]+1,i)==h1[j] && query2(i-len[j]+1,i)==h2[j]){
				++res;
//				printf("%d %d %d\n", i-len[j]+1, i, j);
			}
		}
	}
	printf("%lld\n", res);
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	base[0] = 1;
	for(int i=1; i<=N-5; ++i) base[i] = base[i-1]*P1%P2;
	for(int i=1; i<=n; ++i){
		scanf("\n%s %s", s1+1, s2+1);
		len[i] = strlen(s1+1);
		for(int j=1; j<=len[i]; ++j){//预处理每一组s1,s2的哈希值 
			h1[i] = (h1[i]*P1%P2+s1[j]-64)%P2;
			h2[i] = (h2[i]*P1%P2+s2[j]-64)%P2;
		}
	}

	int siz;
	while(q--){
		scanf("\n%s %s", t1+1, t2+1);
		solve(); 
	}
	return 0;
}
