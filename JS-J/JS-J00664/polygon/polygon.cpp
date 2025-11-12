#include <bits/stdc++.h>
using namespace std;

const long long P = 998244353;

// 9:45 I'm not understand why I think T4 < T3.
// 10:03 I know why is a <= 5000 now.
// 10:26 pretest#1 WA.
// 10:37 pretest#3 WA, debuging.
// 11:02 It's wrong.
// 11:14 RE.
// 11:22 It's still WA, I'm not understand.
// 11:37 It's failed, 200 end. what happened in the afternoon? I can't imagned.
// 11:40 The end.

int n, a[5007], s[5007], l[5007], r[5007], j2[5007];

long long ans[5007]; // sort id

long long mr[10007][5007];

pair<int, int> p[5007]; // first -> value | second -> id

bool cmp(const pair<int, int> &x, const pair<int, int> &y){
	return x.first < y.first;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	j2[0] = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		p[i].first = a[i];
	       	p[i].second = i;
		j2[i] = (j2[i - 1] << 1) % P;
	}
	for(int i = 0; i <= 10000; i++){
		for(int j = 1; j <= n; j++){
			mr[i][j] = ((i >= a[j] ? mr[i - a[j]][j - 1] : j2[j - 1]) + mr[i][j - 1]) % P;
//			if(i <= 100) cout << mr[i][j] << " \n"[j == n];
		}
	}
	for(int i = 1; i <= n; i++){
		l[i] = r[i] = i;
		while(l[i] > 1 && a[l[i] - 1] < a[i]) --l[i];
		while(r[i] < n && a[r[i] + 1] < a[i]) ++r[i];
	}
	sort(p + 1, p + n + 1, cmp);
	for(int i = 1; i <= n; i++){
//		cout << l[p[i].second] << " " << p[i].second << " " << r[p[i].second] << "\n";
		ans[i] = (ans[i - 1] + mr[p[i].first << 1][r[p[i].second]] - mr[max((p[i].first << 1), s[r[p[i].second]] - s[l[p[i].second] - 1])][l[p[i].second] - 1]) % P;
//		for(int j = l[p[i].second]; j <= r[p[i].second]; j++){
//			if(j == i) continue;
//			ans[i] -= mr[p[i].first << 1][min(r[p[i].second], r[p[j].second])] - mr[p[i].first << 1][max(l[p[i].second], l[p[j].second]) - 1];
//			ans[i] = (ans[i] + P) % P;
//		}
		ans[i] -= mr[p[i].first << 1][r[p[i].second]] - mr[max((p[i].first << 1), s[r[p[i].second]] - s[p[i].second])][p[i].second];
//		ans[i] = (ans[i] + P) % P;
		ans[i] -= mr[p[i].first << 1][p[i].second - 1] - mr[max((p[i].first << 1), s[p[i].second - 1] - s[l[p[i].second] - 1])][l[p[i].second] - 1];
//		ans[i] = (ans[i] + P) % P;
		ans[i] %= P;
//		cout << ans[i] << "\n";
	}
	printf("%lld\n", ans[n]);
	return 0;
}
