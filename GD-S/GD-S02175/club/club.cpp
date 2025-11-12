#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
using namespace std;

const int N=1e5+10;
int n, T, m1, m2, m3;
bool vis[N];
ll ans;

struct node {
	int a, b, c;
}A[N], B[N], C[N], d[N];

bool cmp1 (node a1, node a2) {return abs (a1.a-max (a1.b, a1.c) ) > abs (a2.a-max (a2.b, a2.c));}
bool cmp2 (node a1, node a2) {return abs (a1.b-max (a1.a, a1.c) ) > abs (a2.b-max (a2.a, a2.c));}
bool cmp3 (node a1, node a2) {return abs (a1.c-max (a1.a, a1.b) ) > abs (a2.c-max (a2.a, a2.b));}

void solve () {
	cin >> n; ans=m1=m2=m3=0;
	for (int i=1; i <= n; i++) {
		cin >> d[i].a >> d[i].b >> d[i].c;
		int mx=max (d[i].a, max (d[i].b, d[i].c) );
		if (d[i].a == mx) A[++m1]=d[i];
		else if (d[i].b == mx) B[++m2]=d[i];
		else C[++m3]=d[i];
//		if (d[i].c > d[i].b && d[i].c > d[i].a) C[++m3]=d[i];
	}
	if (m1 <= n/2 && m2 <= n/2 && m3 <= n/2) {
//		cout << "1 " << m1 << ' ' << m2 << ' ' << m3 << ' ';
		for (int i=1; i <= m1; i++) ans+=A[i].a;
		for (int i=1; i <= m2; i++) ans+=B[i].b;
		for (int i=1; i <= m3; i++) ans+=C[i].c;
		cout << ans << '\n';
		return ;
	}
	if (m1 > m2 && m1 > m3) {
		for (int i=1; i <= m2; i++) ans+=B[i].b;
		for (int i=1; i <= m3; i++) ans+=C[i].c;
		sort (A+1, A+m1+1, cmp1);
		for (int i=1; i <= n/2; i++) ans+=A[i].a;
		for (int i=n/2+1; i <= m1; i++) ans+=max (A[i].b, A[i].c);
	}
	else if (m2 > m1 && m2 > m3) {
		for (int i=1; i <= m1; i++) ans+=A[i].a;
		for (int i=1; i <= m3; i++) ans+=C[i].c;
		sort (B+1, B+m2+1, cmp2);
		for (int i=1; i <= n/2; i++) ans+=B[i].b;
		for (int i=n/2+1; i <= m2; i++) ans+=max (B[i].a, A[i].c);
	}
	else {
		for (int i=1; i <= m1; i++) ans+=A[i].a;
		for (int i=1; i <= m2; i++) ans+=B[i].b;
		sort (C+1, C+m3+1, cmp3);
		for (int i=1; i <= n/2; i++) ans+=C[i].c;
		for (int i=n/2+1; i <= m3; i++) ans+=max (C[i].a, C[i].b);
	}
	cout << ans << '\n';
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> T;
	while (T--) solve ();
	return 0;
}
