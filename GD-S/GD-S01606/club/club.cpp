#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll t, n, a[N][5], cnt[5], anss, sum, aa[N];
bool flag1;
void dfs(int idx){
	if(idx > n){
		anss = max(anss, sum);
		return;
	}
	// 根据每一个人的需求，暴力模拟所有结果 
	for(int i = 1; i <= 3; i++){
		if(cnt[i] == (n>>1)) continue;
		cnt[i]++;
		sum += a[idx][i];
		dfs(idx+1);
		sum -= a[idx][i];
		cnt[i]--;
	}
}

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		memset(cnt, 0, sizeof cnt);
		memset(a, 0, sizeof a);
		cin >> n;
		flag1 = 1;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1];
			cin >> a[i][2];
			cin >> a[i][3];
			if(a[i][2] || a[i][3]) flag1 = 0;// A
		}
		if(flag1){
			for(int i = 1; i <= n; i++) aa[i] = a[i][1];
			sort(aa+1, aa+n+1, cmp);
			int uu = 0;
			for(int i = 1; i <= (n>>1); i++){
				uu += aa[i];
			}
			cout << uu << "\n";
			continue;
		}
		anss = 0;
		dfs(1);
		cout << anss << '\n'; 
	} 
	return 0;
} 
