//CSP 2025 RP++
#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
using namespace std;
const int N = 5e6+5;
template<typename Tp> inline void read(Tp &x){
	x = 0; char c; bool f = false;
	for(c = gc(); !isdigit(c); c = gc()) if(c == '-') f = true;
	for( ; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = f ? -x : x;
}
int n, k, cnt, ans, a[N], s[N];
vector<int> last[N];
inline bool find(int idx, int st, int en){
	int l = 0, r = last[idx].size() - 1, ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(last[idx][mid] > st) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	return last[idx][ans] <= en && ans != -1;
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	read(n), read(k);
	last[0].push_back(1);
	for(int i = 1; i <= n; i++){
		read(a[i]);
		s[i] = s[i - 1] ^ a[i];
		last[s[i]].push_back(i + 1);
	}
	for(int now = 0, i = 1; i <= n; i++){
		if(find(s[i] ^ k, now, i)) ++ans, now = i;
	}
	printf("%d", ans);
	return 0;
}
