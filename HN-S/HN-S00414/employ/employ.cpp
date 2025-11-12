#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
int n, m, ans, p[N], c[N];
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) p[i] = i;
	for(int i = 1; i <= n; i++) cin >> c[i];
	do{
		int pre = 0, cnt = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] - '0' == 1 && pre < c[p[i]]){
				cnt++;
			}else{
				pre++;
			}
		}
		if(cnt >= m) ans++;
	}while(next_permutation(p + 1, p + 1 + n));
	cout << ans;
	return 0;
}
