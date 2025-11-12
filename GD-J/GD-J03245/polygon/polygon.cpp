#include<bits/stdc++.h> 
using namespace std;

int n, s[5005];
int MOD=998244353;
long long cnt[5005][5005];

int l[5005];
long long c=0;
void dfs(int p, int k) {
	if (p>=n) {
		int sum=0, mmax=-1;
		for (int i=0;i<k;i++) {
			sum+=l[i];
			mmax = max(mmax, l[i]);
		}
		if (sum>mmax*2 && k>2) c++;
		return;
	}
	l[k] = s[p];
	dfs(p+1, k+1);
	l[k] = 0;
	dfs(p+1, k);
	return;
	
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin>>n;
	
	for (int i=0;i<n;i++) {
		cin>>s[i];
	}
	
	dfs(0, 0);
	cout<<c%MOD;
	return 0;
} 
