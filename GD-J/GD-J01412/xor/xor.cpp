#include<bits/stdc++.h>
using namespace std;
int n, k, s[500005], f[500005];
vector<int>m[1048576];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
		s[i] = s[i - 1] ^ s[i];
	}
	m[0].push_back(0);
	for(int i = 1; i <= n; i++){
		f[i] = f[i - 1];
		for(int j:m[s[i] ^ k]){
			f[i] = max(f[j] + 1, f[i]);
		}
		m[s[i]].push_back(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}
