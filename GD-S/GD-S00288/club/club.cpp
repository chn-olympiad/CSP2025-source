#include <bits/stdc++.h>
#define f(i,a,b) for ( int i = a ; i <= b ; i++ )
#define rt return
using namespace std;
const int maxn=1e5+5;
int t,n,num[4],wrong=0,ok[5];
struct member {
	int like[4],choose;
	member(int a=0, int b=0, int c=0) {
		like[1]=a; like[2]=b; like[3]=c;
	}
} m[maxn];

inline int rd() {
	int x=0;
	char c=getchar();
	bool p=true;
	while ( c < '0' || c > '9' ) {
		if ( c == '-' ) p = false;
		c=getchar();
	}
	while ( c >= '0' && c <= '9' ) {
		x = x*10 + c - '0';
		c=getchar();
	}
	rt p ? x : -x;
}
/*
inline void in() {
	scanf("%d", &n);
	f(i,1,3) num[i]=0;
	f(i,1,n) f(j,1,3) scanf("%d", &like[i][j]);
	rt;
}*/
inline void in() {
	scanf("%d", &n);
	f(i,1,3) num[i]=0;
	f(i,1,n) f(j,1,3) m[i].like[j] = rd();//("%d", &m[i].like[j]);
	rt;
}
/*
inline void set(int i) {
	if ( like[i][1] >= max(like[i][2], like[i][3]) ) choose[i]=1, num[1]++;
	else if ( like[i][2] >= max(like[i][1], like[i][3]) ) choose[i]=2, num[2]++;
	else choose[i]=3, num[3]++;
	rt;
}*/
inline bool OK() {
	f(i,1,3) if ( num[i] > n/2 ) rt false;
	rt true;
}
inline void set_(member &M) {
	if ( M.like[1] >= max(M.like[2], M.like[3]) ) M.choose=1, num[1]++;
	else if ( M.like[2] >= max(M.like[1], M.like[3]) ) M.choose=2, num[2]++;
	else M.choose=3, num[3]++;
	rt;
}
/*
inline int sum() {
	int S=0;
	f(i,1,n) S += like[i][choose[i]];
	rt S;
}*/
inline int sum() {
	int S=0;
	f(i,1,n) S += m[i].like[m[i].choose];
	rt S;
}
inline void get_wrong() {
	wrong=0;
	int cnt=0;
	f(i,1,3) if ( num[i] > n/2 ) {
		wrong=i;
	} else {
		ok[++cnt]=i;
	}
	rt;
}
inline bool cmp(member a, member b) {
	rt a.like[wrong] - max(a.like[ok[1]], a.like[ok[2]]) > b.like[wrong] - max(b.like[ok[1]], b.like[ok[2]]);
}
inline int sum2(member W[], int cnt) {
	int S=0;
	f(i,1,n) if ( m[i].choose != wrong ) S += m[i].like[m[i].choose];
	f(i,1,n/2) S += W[i].like[wrong];
	f(i,n/2+1,cnt) S += max(W[i].like[ok[1]], W[i].like[ok[2]]);
	rt S;
}
inline void redoit() {
	get_wrong();
	member W[maxn]; int cnt=0;
	if ( wrong == 0 ) rt;
	
	f(i,1,n) if ( m[i].choose == wrong ) W[++cnt] = m[i];
	sort(W+1, W+cnt+1, cmp);
	printf("%d", sum2(W, cnt));
	cout << endl;
	rt;
}
inline void doit() {
	f(i,1,n) set_(m[i]);
	if (OK()) {
		printf("%d", sum());
		cout << endl;
	}
	else redoit();
	rt;
}
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		in();
		doit();
	}
	rt 0;
}
