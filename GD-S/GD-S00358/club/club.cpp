#include<bits/stdc++.h>
using namespace std;
int n;
struct P{
	long long idx, mx;
} l[100005]; 
long long sum[100005][4], li[100005][4], mp[100005][4], answ = 0;
bool cmp(P x, P y){
	return x.mx > y.mx;
}
void dfs(int now, int a, int b, int c, long long ans){
	if(now > n){
		answ = max(ans, answ);
		return ;
	}
	if(a == n / 2){
		dfs(now + 1, a, b + 1, c, mp[now][2] + ans);
		dfs(now + 1, a, b, c + 1, mp[now][3] + ans);
	} else if(c == n / 2){
		dfs(now + 1, a, b + 1, c, mp[now][2] + ans);
		dfs(now + 1, a + 1, b, c, mp[now][1] + ans);
	} else if(b == n / 2){
		dfs(now + 1, a + 1, b, c, mp[now][1] + ans);
		dfs(now + 1, a, b, c + 1, mp[now][3] + ans);
	} else {
		dfs(now + 1, a + 1, b, c, mp[now][1] + ans);
		dfs(now + 1, a, b + 1, c, mp[now][2] + ans);
		dfs(now + 1, a, b, c + 1, mp[now][3] + ans);
	}
	return ;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		answ = 0;
		bool x = 1;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> li[i][1] >> li[i][2] >> li[i][3];
			l[i].idx = i;
			l[i].mx = max(li[i][1], max(li[i][2], li[i][3]));
			if(li[i][3] != 0) x = 0;
		}
		sort(l + 1, l + n + 1, cmp);
		for(int i = 1; i <= n; i++){
			mp[i][1] = li[l[i].idx][1];
			mp[i][2] = li[l[i].idx][2];
			mp[i][3] = li[l[i].idx][3];
		}
//		cout << 1;
		if(x){
			long long anss = 0;
			int a = 0, b = 0;
			for(int i = 1; i <= n; i++){
				if(a == n / 2){
					anss += 1ll * mp[i][2];
				} else if(b == n / 2){
					anss += 1ll * mp[i][1];
				} else if(mp[i][1] > mp[i][2]){
					a++;
					anss += 1ll * mp[i][1];
				} else {
					b++;
					anss += 1ll * mp[i][2];
				}
			}
			cout << anss << "\n";
			continue;
		}
		dfs(1, 0, 0, 0, 0);
		cout << answ << "\n";
	}
	return 0;
}
