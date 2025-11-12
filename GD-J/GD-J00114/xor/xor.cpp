#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[int(5e5 + 5)] = {};
int sum[int(5e5 + 5)] = {}, dp1[int(5e5 + 5)] = {};
vector<pair<int, int> > v; 

void solve1(){
	for (int i=1;i<=n;i++) sum[i] = sum[i-1] ^ a[i];
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if ((sum[j] ^ sum[i-1]) == k){
				v.push_back({i,  j});
			}
		}
	}
	for (int i=0;i<v.size();i++){
		int maxx = 0;
		for (int j=0;j<i;j++){
			if (v[i].first > v[j].second) maxx = max(maxx, dp1[j]);
		}
		dp1[i] = maxx + 1;
	}
	int maxx = 0;
	for (int i=0;i<v.size();i++){
		maxx = max(maxx, dp1[i]);
	}
	printf("%d\n", maxx);
	return ;
}
int xxors[int(5e5 + 5)][5] = {}, dp[int(5e5 + 5)][5] = {};
void solve2(){
	for (int i=1;i<=n;i++) xxors[i][0] = xxors[i][1] = a[i];
	if (xxors[1][0] == k) dp[1][1] = dp[1][0] = 1;
	for (int i=2;i<=n;i++){
		int cnt1 = dp[i-1][0], cnt2 = dp[i-1][1];
		if ((xxors[i][0] ^ xxors[i-1][0]) == k && xxors[i-1][0] != k){cnt1 ++;} 
		else if ((xxors[i][0] ^ xxors[i-1][0]) != k && xxors[i-1][0] == k) cnt1 --;
		if ((xxors[i][0] ^ xxors[i-1][1]) == k && xxors[i-1][1] != k) cnt2 ++;
		else if ((xxors[i][0] ^ xxors[i-1][1]) != k && xxors[i-1][1] == k) cnt2 --;
		if (cnt1 >= cnt2){
			dp[i][0] = cnt1, xxors[i][0] ^= xxors[i-1][0];
		}
		else dp[i][0] = cnt2, xxors[i][0] ^= xxors[i-1][1];
		
		cnt1 = dp[i-1][0], cnt2 = dp[i-1][1];
		if (xxors[i][1] == k) cnt1 ++, cnt2 ++;
		dp[i][1] = max(cnt1, cnt2);
	}
	int maxx = 0;
	for (int i=1;i<=n;i++){
		if (xxors[i][0] == k) maxx = max(maxx, dp[i][0]);
		if (xxors[i][1] == k) maxx = max(maxx, dp[i][1]);
	}
	cout << maxx << endl;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	if (n <= 1000){
		solve1();
	}else {
		solve2();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

