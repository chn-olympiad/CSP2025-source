#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 10;
int t;
struct jkl{
	long long a,b,c,maxx,mx;
}s[maxn];
bool cmp(jkl x,jkl y) {
	return x.maxx > y.maxx;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
			s[i].maxx = max(s[i].a,max(s[i].b,s[i].c));
			if (s[i].maxx == s[i].a) {
				s[i].mx = max(s[i].b,s[i].c);
			} else if (s[i].maxx == s[i].b) {
				s[i].mx = max(s[i].a,s[i].a);
			}else if (s[i].maxx == s[i].c) {
				s[i].mx = max(s[i].a,s[i].b);
			}
			
		}
	
		long long cnta = 0,cntb = 0,cntc = 0;
		long long ans = 0;
		priority_queue<long long> q1,q2,q3;
		for (int i = 1; i <= n; i++) {
			ans += s[i].maxx;
			if (s[i].maxx == s[i].a) {
				cnta++;
				q1.push(-s[i].maxx + s[i].mx);
			} else if (s[i].maxx == s[i].b) {
				cntb++;
				q2.push(-s[i].maxx + s[i].mx);
			}else if (s[i].maxx == s[i].c) {
				cntc++;
				q3.push(-s[i].maxx + s[i].mx);
			}
			
		}
		if (cnta > n / 2) {
			for (int i = 1; i <= cnta - n / 2; i++) {
				ans += q1.top();
				q1.pop();
			}
		}
		if (cntb > n / 2) {
			for (int i = 1; i <= cntb - n / 2; i++) {
				ans += q2.top();
				q2.pop();
			}
		}
		if (cntc > n / 2) {
			for (int i = 1; i <= cntc - n / 2; i++) {
				ans += q3.top();
				q3.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
