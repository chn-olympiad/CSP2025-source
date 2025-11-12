#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 2;
struct node{
	int x, y, z;
}s[maxn];
int t, n;
bool flag1;
int dp[5][maxn];
bool cmp(node x, node y){
	if(x.x > y.x)
		return true;
	return false;
}
void f1(){
	sort(s + 1, s + n + 1, cmp);
	int ans = 0;
	for(int i = 1; i <= n / 2; i++)
		ans += s[i].x;
	cout << ans;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> s[i].x >> s[i].y >> s[i].z;
			if(s[i].y != 0 || s[i].z != 0)
				flag1 = true;
		}
		if(!flag1)
			f1();
	}
	return 0;
}
