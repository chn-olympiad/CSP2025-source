#include <bits/stdc++.h>
#define f(i,a,b) for ( int i = a ; i <= b ; i++ )
#define rt return
using namespace std;
const int maxn=2e5+2;
int n,q,st,ed;
struct turn {
	string from,to;
	string fac_from,fac_to;
} t[maxn];

inline void pre() {
	int l;
	f(i,1,n) {
		l = t[i].from.size()-1;
		f(j,0,l);
	}
}
inline void in() {
	scanf("%d%d", &n, &q);
	f(i,1,n) cin >> t[i].from >> t[i].to;
	pre();
	rt;
}
inline void doit() {
	;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	in();
	doit();
	rt 0;
}
