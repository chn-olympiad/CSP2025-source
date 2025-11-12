#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ull;
const int L = 5e6 + 5, N = 2e5 + 5;
int n, q, l[N];
ull a[N], b[N], h2[N], h[N], p[N];
ull get(int l, int r){
	return h[r] - h[l] * p[r - l + 1];
}
ull get2(int l, int r){
	return h2[r] - h2[l] * p[r - l + 1];
}
char s1[L], s2[L];
bool check(int i){
	for (int j = 1; j <= n; j++){
		if (j >= l[i] && get(j - l[i] + 1, j) == a[i]){
			if (get2(j - l[i] + 1, j) != b[i]){
				return false;
			}
			j += l[i] - 1;
		}else if (s1[j] != s2[j]){
			return false;
		}
	}
	return true;
}
int b1[N], b2[N];
bool check2(int i, int ba, int bb, int la){
	if (b1[i] < ba || ba - b1[i] + l[i] > la || b2[i] < bb || bb - b2[i] + l[i] > la || b2[i] - b1[i] != bb - ba){
		return false;
	}else return true;
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i++){
		scanf("%s%s", s1 + 1, s2 + 1);
		l[i] = strlen(s1 + 1);
		for (int j = 1; j <= l[i]; j++){
			a[j] = a[j] * 29 + s1[j] - '0' + 1;
			b[j] = b[j] * 29 + s2[j] - '0' + 1;
			s1[j] = s2[j] = ' ';
			if (s1[j] == 'b') b1[i] = j;
			if (s2[j] == 'b') b2[i] = j;
		}
	}
	for (int i = 1; i <= q; i++){
		scanf("%s%s", s1 + 1, s2 + 1);
		int la = strlen(s1 + 1), lb = strlen(s2 + 1);
		if (la != lb){
			printf("0\r\n");
			continue;
		} 
		p[0] = 1;
		int ba = 0, bb = 0;
		for (int j = 1; j <= la; j++){
			h[j] = h[j] * 29 + s1[j] - '0' + 1;
			p[j] = p[j - 1] * 29;
			h2[j] = h2[j] * 29 + s2[j] - '0' + 1;
			if (s1[j] == 'b') ba = j;
			if (s2[j] == 'b') bb = j;
		}
		int ans = 0;
		if (n * n < 1e7 / q){
			for (int i = 1; i <= n; i++){
				if (check(i)) ans++;
			}
		}else{
			for (int i = 1; i <= n; i++){
				if (check2(i, ba, bb, la)) ans++;
			}
		}
		printf("%lld\r\n", ans);
	}
	return 0;
}
