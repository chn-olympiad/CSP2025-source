#include <bits/stdc++.h>

using namespace std; 

int TEST, n, maxn;
int A[100005], B[100005], C[100005];
bool AA; 

int acnt, bcnt, ccnt, asum, bsum, csum;
void Dfs (int cur) {
	if (cur == n + 1) {
		maxn = max(maxn, asum + bsum + csum);
		return;
	}
	if (acnt != n / 2) {
		asum += A[cur];
		acnt++;
		Dfs(cur + 1);
		asum -= A[cur];
		acnt--;
	}
	if (bcnt != n / 2) {
		bsum += B[cur];
		bcnt++;
		Dfs(cur + 1); 
		bsum -= B[cur];
		bcnt--;
	}
	if (ccnt != n / 2) {
		csum += C[cur];
		ccnt++;
		Dfs(cur + 1);
		csum -= C[cur];
		ccnt--;
	}
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	
	cin >> TEST;
	
	while (TEST--) {
		AA = 1;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> A[i] >> B[i] >> C[i];
			if (B[i] || C[i]) AA = 0;
		}
		
		if (AA) {
			vector<int> T;
			for (int i = 1; i <= n; i++) 
				T.push_back(A[i]);
			sort(T.begin(), T.end());
			maxn = 0;
			for (int i = T.size() - 1; i; i--) 
				maxn += T[i];
			cout << maxn << '\n';
		} else {
			maxn = 0;
			Dfs(1);
			cout << maxn << '\n'; 
		}
	}
	
	return 0;
}