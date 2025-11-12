//goal:12pts,love from CCF ren jie di ling
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int n,m,c[505],p[505],away,cnt;
long long res;
bool subtask = true;
string s;
inline int check(){
	away = cnt = 0;
	for (int i = 1;i <= n;++i){
		if (away >= c[p[i]]) ++away;
		else{
			if (s[i - 1] == '1') ++cnt;
			else ++away;
			if (cnt >= m) return 1;	
		}
	}
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;++i) cin >> c[i];
	for (int i = 0;i < s.size();++i) if (s[i] == '0') subtask = false;
	if (m == n){
		if (subtask){
			for (int i = 1;i <= n;++i) 
				if (!c[i]){
					cout << 0;
					return 0;
				}
		}else{
			cout << 0;
			return 0;
		}
	}else{
		for (int i = 1;i <= n;++i) p[i] = i;
		do{
			res += check();
		}while (next_permutation(p + 1,p + 1 + n));
		cout << res;
		return 0;
	}
}
