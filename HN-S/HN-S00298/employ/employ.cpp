#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m, Arr[510], dp[2][510][510], t[510], T[510], id[510];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	int cnt = 0;
	for(int i = 1; i <= n; i ++){
		cin >> Arr[i];
		id[i] = i;
		if(!Arr[i]) ++ cnt;
	}
	int Cnt = 0;
	for(auto i:s){
		if(i == '1') ++ Cnt;
	}
	if(m > Cnt) cout << 0;
	else{
		if(m == n){
			if(cnt) cout << 0;
			else{
				int Ans = 1;
				for(int i = 1; i <= n; i ++) Ans = Ans * i % mod;
				cout << Ans;
			}
		}else if(n <= 10){
			s = " " + s;
			int Ans = 0;
			do{
				int lst = 0, num = 0;
				for(int i = 1; i <= n; i ++){
					if(Arr[id[i]] <= lst || s[i] == '0') ++ lst;
					else ++ num;
				}
				Ans += (num >= m); 
				Ans = (Ans >= mod) ? Ans - mod : Ans;
			}while(next_permutation(id + 1, id + n + 1));
			cout << Ans;
		}else{
			cout << 0 << '\n';
		}
	}
}
