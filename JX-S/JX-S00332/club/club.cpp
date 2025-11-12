#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n;
struct sb {int x, y, z;} a[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q1, q2, q3;
void work() {
	int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        int sum = a[i].x + a[i].y + a[i].z;
        int tmp = sum - max(a[i].x, max(a[i].y, a[i].z)) - min(a[i].x, min(a[i].y, a[i].z));
        if(a[i].x > tmp) {
        	q1.push({a[i].x - tmp, i});
        	ans += a[i].x;
        } else if(a[i].y > tmp) {
        	q2.push({a[i].y - tmp, i});
        	ans += a[i].y;
        } else if(a[i].z > tmp) {
        	q3.push({a[i].z - tmp, i});
        	ans += a[i].z;
        } else ans += max(a[i].x, max(a[i].y, a[i].z));
    }
    while(q1.size() > n / 2) {
        ans -= q1.top().first;
        q1.pop();
    }
    while(q2.size() > n / 2) {
        ans -= q2.top().first;
        q2.pop();
    }
    while(q3.size() > n / 2) {
        ans -= q3.top().first;
        q3.pop();
    }
    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
    while(!q3.empty()) q3.pop();
    cout << ans << "\n";
    return ;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) work();
    return 0;
}
