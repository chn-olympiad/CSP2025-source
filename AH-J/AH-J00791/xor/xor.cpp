#include<bits/stdc++.h>
using namespace std;

const int MAXNUM = 3000005;

int n, k;
int f[MAXNUM];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	int a, dp = 0, sum = 0;
	
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		sum = sum ^ a;
		
		dp = max(dp, f[ (sum ^ k) ] + 1);
		f[sum] = max(f[sum], dp);
	}
	
	cout << dp << endl;
	
	return 0;
}
