#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int P = 998244353;
int ans = 0;
int n,m;
char s[N];
int c[N];
int p[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	scanf("%s", s+1);
	for(int i = 1; i <= n; i++) scanf("%d", c+i), p[i] = i;
	
	do{
		int unpass = 0;
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '0') unpass++;
			else if(unpass >= c[p[i]]) unpass++;
			else cnt++;
		}
		if(cnt >= m) ans++;
	}while(next_permutation(p+1,p+1+n));
	cout << ans;
	return 0;
}
