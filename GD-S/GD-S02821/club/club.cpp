#include <bits/stdc++.h>
using namespace std;
struct node{
	int v1, v2, v3;
}a[100010];
int t, n, ans, ans1;
priority_queue<pair<int, int> > q1, q2, q3;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t -- && cin >> n){
		for (int i = 1; i <= n; i ++)cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
		ans = 0;
		while (q1.size())q1.pop();
		while (q2.size())q2.pop();
		while (q3.size())q3.pop();
		for (int i = 1, nmax; i <= n; i ++){
			nmax = max(a[i].v1, max(a[i].v2, a[i].v3));
			if (nmax == a[i].v1)
				q1.push({max(a[i].v2, a[i].v3) - a[i].v1, i}), ans += a[i].v1;
			else if (nmax == a[i].v2)
				q2.push({max(a[i].v1, a[i].v3) - a[i].v2, i}), ans += a[i].v2;
			else
				q3.push({max(a[i].v1, a[i].v2) - a[i].v3, i}), ans += a[i].v3;
		}
		while (q1.size() > n / 2){
			pair<int, int> now = q1.top();
			q1.pop(), ans -= a[now.second].v1;
			if (now.first == a[now.second].v2 - a[now.second].v1)
				q2.push({max(a[now.second].v1, a[now.second].v3) - a[now.second].v2, now.second}), ans += a[now.second].v2;
			else
				q3.push({max(a[now.second].v1, a[now.second].v2) - a[now.second].v3, now.second}), ans += a[now.second].v3;
		}
		while (q2.size() > n / 2){
			pair<int, int> now = q2.top();
			q2.pop(), ans -= a[now.second].v2;
			if (now.first == a[now.second].v1 - a[now.second].v2 && q1.size() < n / 2)
				q1.push({max(a[now.second].v2, a[now.second].v3) - a[now.second].v1, now.second}), ans += a[now.second].v1;
			else
				q3.push({max(a[now.second].v1, a[now.second].v2) - a[now.second].v3, now.second}), ans += a[now.second].v3;
		}
		while (q3.size() > n / 2){
			pair<int, int> now = q3.top();
			q3.pop(), ans -= a[now.second].v3;
			if (now.first == a[now.second].v1 - a[now.second].v3 && q1.size() < n / 2)
				q1.push({max(a[now.second].v2, a[now.second].v3) - a[now.second].v1, now.second}), ans += a[now.second].v1;
			else q2.push({max(a[now.second].v1, a[now.second].v3) - a[now.second].v2, now.second}), ans += a[now.second].v2;
		}
		cout << ans << '\n';
	}
	return 0;	
}
/*
可以定义三个优先队列存储各部门的成员
每次若超人了，就把其中剩下两满意度最大的放进另一队列
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13	
*/
