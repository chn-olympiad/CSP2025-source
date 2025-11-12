#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
class Member {
public:
	pair<int, int> s[3];
	int dif;
	Member(int a, int b, int c) {
		s[0] = {a, 0}, s[1] = {b, 1}, s[2] = {c, 2};
		sort(s, s + 3);
		dif = s[2].x - s[1].x;
	}
	
	bool operator < (Member p) const {
		return dif < p.dif;
	}
};
int n;
vector<Member> a;
priority_queue<Member> pq[3];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T, s1, s2 ,s3;
	scanf("%d", &T);
	while (T--) {
		a.clear();
		for (int i = 0; i < 3; ++i) while(!pq[i].empty()) pq[i].pop();
		scanf("%d", &n);
		int hn = n >> 1, deg[3] = {0, 0, 0};
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &s1, &s2, &s3);
			a.push_back(Member(s1, s2, s3));
		}
		for (Member p: a) {
			if (pq[p.s[2].y].size() < hn) pq[p.s[2].y].push(p), deg[p.s[2].y] += p.s[2].x;
			else {
				Member t = pq[p.s[2].y].top();
				if (t.dif < p.dif) {
					pq[p.s[2].y].pop();
					pq[p.s[2].y].push(p);
					pq[t.s[1].y].push(t);
					deg[p.s[2].y] = deg[p.s[2].y] - t.s[2].x + p.s[2].x;
					deg[t.s[1].y] += t.s[1].x;
				}
				else pq[p.s[1].y].push(p), deg[p.s[1].y] += p.s[1].x;
			}
		}
		printf("%d\n", deg[0] + deg[1] + deg[2]);
	}
	return 0;
}

