#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct p{
	int x, y, z;
} a[100005];
int t, n, ans;
bool cmp(p a, p b){
	return a.x + b.z > b.x + a.z;
}
bool cmp2(p a, p b){
	if(a.x + b.y == b.x + a.y) return a.x > b.x;
	return a.x + b.y > b.x + a.y;
}
bool cmpv1(int x, int y){
	return min(a[x].x - a[x].y, a[x].x - a[x].z) < min(a[y].x - a[y].y, a[y].x - a[y].z);
}
bool cmpv2(int x, int y){
	return min(a[x].y - a[x].x, a[x].y - a[x].z) < min(a[y].y - a[y].x, a[y].y - a[y].z);
}
bool cmpv3(int x, int y){
	return min(a[x].z - a[x].y, a[x].z - a[x].x) < min(a[y].z - a[y].y, a[y].z - a[y].x);
}
void dfs(int step, int n1, int n2, int n3, int s){
	if(step > n){
		ans = max(ans, s);
		return;
	}
	if(n1 < n / 2)
	dfs(step + 1, n1 + 1, n2, n3, s + a[step].x);
	if(n2 < n / 2)
	dfs(step + 1, n1, n2 + 1, n3, s + a[step].y);
	if(n3 < n / 2)
	dfs(step + 1, n1, n2, n3 + 1, s + a[step].z);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		ans = 0;
		bool fa = 1, fb = 1;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].z) fa = fb = 0;
			if(a[i].y) fa = 0;
		}
		if(fa){
			sort(a + 1, a + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++) ans += a[i].x;
			cout << ans << '\n';
			continue;
		}
		if(fb){
			sort(a + 1, a + n + 1, cmp2);
			for(int i = 1; i <= n / 2; i++) ans += a[i].x;
			for(int i = n / 2 + 1; i <= n; i++) ans += a[i].y;
			cout << ans << '\n';
			continue;
		}
		if(n <= 15){
			dfs(1, 0, 0, 0, 0);
			cout << ans << '\n';
			continue;
		}
		vector<int> v1, v2, v3;
		for(int i = 1; i <= n; i++){
			if(a[i].x >= a[i].y && a[i].x >= a[i].z){
				v1.push_back(i);
			}
			else if(a[i].y >= a[i].x && a[i].y >= a[i].z){
				v2.push_back(i);
			}
			else{
				v3.push_back(i);
			}
		}
		int s1 = v1.size(), s2 = v2.size(), s3 = v3.size();
		if(s1 > n / 2){
			sort(v1.begin(), v1.end(), cmpv1);
			for(int i = 0; i < s1 - n / 2; i++){
				int id = v1[i];
				if(a[id].y > a[id].z && v2.size() < n / 2) v2.push_back(id);
				else v3.push_back(id);
			}
		}
		if(s2 > n / 2){
			sort(v2.begin(), v2.end(), cmpv2);
			for(int i = 0; i < s2 - n / 2; i++){
				int id = v2[i];
				if(a[id].x > a[id].z && v1.size() < n / 2) v1.push_back(id);
				else v3.push_back(id);
			}
		}
		if(v3.size() > n / 2){
			sort(v3.begin(), v3.end(), cmpv3);
			for(int i = 0; i < s3 - n / 2; i++){
				int id = v3[i];
				if(a[id].y > a[id].x && v2.size() < n / 2) v2.push_back(id);
				else v1.push_back(id);
			}
		}
		s1 = v1.size(), s2 = v2.size(), s3 = v3.size();
		for(int i = 0; i < min(n / 2, s1); i++) ans += a[v1[i]].x;
		for(int i = 0; i < min(n / 2, s2); i++) ans += a[v2[i]].y;
		for(int i = 0; i < min(n / 2, s3); i++) ans += a[v3[i]].z;
		cout << ans << '\n';
	}
	return 0;
}
