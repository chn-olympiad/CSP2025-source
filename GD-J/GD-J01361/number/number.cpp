#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define inl inline
#define rep(i,l,r) for(ri i = l; i <= r; i ++)
#define per(i,r,l) for(ri i = r; i >= l; i ++)
#define N 1000005
string s;
int ls;
int a[N], tot;
inl bool cmp(int x, int y){
	return x > y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ls = s.size();
	for(ri i = 0; i < ls; i ++){
		if('0' <= s[i] && s[i] <= '9') a[++ tot] = s[i] - '0';
	}
	sort(a + 1, a + tot + 1, cmp);
	rep(i, 1, tot) cout << a[i];
	return 0;
}

