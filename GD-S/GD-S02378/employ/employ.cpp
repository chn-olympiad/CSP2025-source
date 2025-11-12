#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("employ.in");
ofstream cout("employ.out");
int n, m, ans, tow[500], state[500], c[500];
bool check(){
	for(int i=0; i<n; i++)
		if(!state[i]) return 0;
	return 1;
}
int multi(int k){
	if(k == 1) return 1;
	if(!c[k - 1]) return multi(k - 1);
	return (1ll*k*multi(k-1)) % 998244353;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string t; cin >> n >> m >> t;
	for(int i=0; i<n; i++)
		cin >> c[i], tow[i] = i, state[i] = t[i] - '0';
	if(check()){cout << multi(n); return 0;}
	do{
		int lose = 0, per = 0;
		for(int i=0; i<n; i++)
			if(lose < c[tow[i]] && state[i]) lose = 0, per++;
			else lose++;
		if(lose < m) ans = (ans + 1) % 998244353; 
	}while(next_permutation(tow, tow + n));
	cout << ans;
	return 0;
}
