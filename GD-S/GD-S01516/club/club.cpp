#include <bits/stdc++.h>
#define int long long
#define INF 0x7fffffff
using namespace std;
const int N = 1e5 + 10;
int T,n,ans;
bool typeA,typeB;

struct Node{
	int a1, a2, a3;
}s[N];
bool operator > (const Node& x, const Node& y){
	if(x.a1 > y.a1) return true;
	else if(x.a1 == y.a1 && x.a2 > y.a2) return true;
	else if(x.a1 == y.a1 && x.a2 == y.a2 && x.a3 > y.a3) return true;
	return false;
}

void dfs(int d, int sum, int a, int b, int c){
	if(d > n){
		ans = max(ans, sum);
		return ;
	}
	if(a < (n >> 1)) dfs(d + 1, sum + s[d].a1, a + 1, b, c);
	if(b < (n >> 1)) dfs(d + 1, sum + s[d].a2, a, b + 1, c);
	if(c < (n >> 1)) dfs(d + 1, sum + s[d].a3, a, b, c + 1);
	
	return ;
}

void dfsB(int d, int sum, int a, int b){
	if(d > n){
		ans = max(ans, sum);
		return ;
	}
	if(a < (n >> 1)) dfsB(d + 1, sum + s[d].a1, a + 1, b);
	if(b < (n >> 1)) dfsB(d + 1, sum + s[d].a2, a, b + 1);
	return ;
}

inline int read()
{
	char c; int x = 0, d = 1;
	for(;!isdigit(c);c=getchar()) if(c == '-') d = -1;
	for(;isdigit(c);c=getchar()) x = x * 10 + c - '0';
	return d * x;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	T = read();
	
	while(T--){
		memset(s, 0, sizeof(s));
		n = read(), ans = 0, typeA = typeB = 1;
		for(int i=1,a,b,c;i<=n;i++){
			a = read(), b = read(), c = read();
			s[i].a1 = a, s[i].a2 = b, s[i].a3 = c;
			if(b + c) typeA = 0;
			if(c) typeB = 0;
		}
		
		
		
		if(typeA){
			sort(s + 1, s + n + 1, greater<Node>());
			for(int i=1;i<=(n >> 1);i++) ans += s[i].a1;
		}
		else if(typeB){
			dfsB(1, 0, 0, 0);
		}
		else dfs(1, 0, 0, 0, 0);
		
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
