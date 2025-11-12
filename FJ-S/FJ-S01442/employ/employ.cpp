#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
const int mod = 998244353;
int n, m, c[N];
string s;
int Exam[N];
bool type = true;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n;
	cin >> m;
	cin >> s;
	int len = s.size();
	s = " " + s;
//	cout << s <<endl;
	for(int i = 1; i <= len; i++){
		Exam[i] = (s[i] - '0');
		if(Exam[i] != 1) type = false;
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(type){
//		cout << 0 << endl;
		int ans = 1;
		for(int i = n; i >= 1; i--){
			ans = (ans * i) % mod;
		}
		cout << ans <<endl;
	}
	return 0;
}
