#include <bits/stdc++.h>
#define ll long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=101;
int n, m;
struct node {int a, id;} s[N];
bool cmp(node x,node y) {return x.a>y.a;}
signed main(void) {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) cin >> s[i].a, s[i].id=i;
	sort(s+1,s+n*m+1,cmp);
	for (int i=1, nx=1, ny=1;i<=n*m;i++) {
		if (s[i].id==1)
			Blackdream1853 cout << ny << ' ' << nx << '\n', code;
		if (ny%2==0) {
			if (nx==1) ny++;
			else nx--;
		} else {
			if (nx==n) ny++;
			else nx++;
		}
	}
	Blackdream1853 code;
}
/*
2 2
99 100 97 98
----1 2
2 2
98 99 100 97
----2 2
3 3
94 95 96 97 98 99 100 93 92
----3 1
4 2
96 100 99 98 97 95 94 93
----2 4
2 4
96 100 99 98 97 95 94 93
----3 1
*/
