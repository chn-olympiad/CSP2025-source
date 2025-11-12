#include <bits/stdc++.h>
using namespace std;
string s;
map<int, int> mp;
int c[1000000];
int p[1000000];
int ans;
int n, m;
void SA(){
	double sta = 10000000, beg = 1e-12, tt = 0.999;
	for(double t = sta; t > beg; t *= tt){
		int x1 = rand() % n + 1;
		int y1 = rand() % n + 1;
		swap(p[x1], p[y1]);
		int cnt =0;
		int cnt1 = 0;
		for(int i = 1;i <= n;i++){
			if(c[p[i]] <= cnt){
				cnt++;
				continue;
			}
			if(mp[i] == 0){
				cnt++;
				continue;
			}
			++cnt1;
		}
		ans += (cnt1 >= m);
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	bool A = 1;
	for(int i = 0;i < s.size();i++){
		mp[i + 1] = s[i] - '0';
		A = min(A, (bool)(s[i] - '0'));
	}
	for(int i = 1; i <= n;i++){
		cin >> c[i];
	}
	if(n <= 10){
		for(int i = 1;i <= n;i++){
			p[i] = i;
		}
		int ans = 0;
		do{
			int cnt =0;
			int cnt1 = 0;
			for(int i = 1;i <= n;i++){
				if(c[p[i]] <= cnt){
					cnt++;
					continue;
				}
				if(mp[i] == 0){
					cnt++;
					continue;
				}
				++cnt1;
			}
			ans += (cnt1 >=m);
			ans %= 998244353;
		}while(next_permutation(p + 1, p + n + 1));
		cout << ans << endl;
	}else{
		for(int i = 1;i <= n;i++){
			p[i] = i;
		}
		for(int i = 1;i <= 30;i++) SA();
		cout << ans << endl;
	}
	return 0; 
} 
