# include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int Mod = 998244353;

int n, m;
string s;
int c[N];
int vis[N];
int ans[N];
long long answer;
int Count_1;

void check (int Ans[]){
	int gu = 0, su = 0;
	for (int i = 0;i < n;i++){
		if (gu >= c[Ans[i]]){
			gu++;
			continue;
		}
		if (s[i] == '0'){
			gu++;
		}
		else {
			su++;
		}
	}
	
	if (su >= m){
		answer++;
		answer %= Mod;
	}
}

void dfs (int pos, int Ans[]){
	if (pos == n){
		check(Ans);
		return ;
	}
	
	for (int i = 0;i < n;i++){
		if (vis[i] == 0){
			vis[i] = 1;
			Ans[pos] = i;
			dfs(pos + 1, Ans);
			vis[i] = 0;
		}
	}
}

int main (){
	
	frepoen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	
	for (int i = 0;i < n;i++){
		cin >> c[i];
	}
	
	for (int i = 0;i < n;i++){
		if (s[i] == '1'){
			Count_1++;
		}
	}
	
	if (Count_1 == n){
		answer = 1;
		for (int i = 1;i <= n;i++){
			answer *= i;
			answer %= Mod;
		}
		cout << answer;
		return 0;
	}
	if (m == 1){
		for (int i = 0;i < n;i++){
			if (s[i] == '1'){
				int a = i;
				answer = 1;
				for (int i = 1;i <= n - a;i++){
					answer *= i;
					answer %= Mod;
				}
				cout << answer;
				return 0;
			}
		}
	}
	else if (m == n){
		for (int i = 0;i < n;i++){
			if (s[i] == '0'){
				cout << 0;
				return 0;
			}
		}
		
		answer = 1;
		for (int i = 1;i <= n;i++){
			answer *= i;
			answer %= Mod;
		}
		cout << answer;
		return 0;
	}
	
	dfs (0, ans);
	
	cout << answer;
	
	return 0;
}
