#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a[500010], s[500010], cnt, ans, s1[500010];
struct P{
	int s, e;
}w[500010];
bool cmp(P c, P b){
	if(c.s == b.s){
		return c.e - c.s < b.e - b.s;
	}
	return c.s < b.s;
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = (s[i - 1] ^ a[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if((s[j] ^ s[i - 1]) == k){
				w[++cnt].s = i;
				w[cnt].e = j;
				s1[cnt] = i;
			}
		}
	}
	cout << cnt;
	return 0;
}