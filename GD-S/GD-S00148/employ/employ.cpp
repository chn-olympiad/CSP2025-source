# include <algorithm>
# include <iostream>
# define FILE
//# define mulq
# define ll long long
using namespace std;
const ll mod = 998244353;
int n,m,hd[910],pat[910],permu[910];
void solve(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		char c; cin >> c;
		hd[i] = (c == '0');
		permu[i] = i;
	}for (int i = 1;i <= n;i++) cin >> pat[i];
	ll cnt = 0;
	do{
		int ccb = n;
		for (int i = 1;i <= n;i++){
			if (hd[i]) ccb--;
			else if (n - ccb >= pat[permu[i]]) ccb--;
		}(cnt += (ccb >= m)) %= mod;
	}while (next_permutation(permu + 1,permu + 1 + n));
	cout << cnt << endl;
}int main(){
	# ifdef FILE
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	# endif
	# ifdef mulq
	int q; cin >> q;
	while (q--) solve();
	# else
	solve();
	# endif
	return 0;
}
