# include <iostream>
# include <cstring>
# define FILE
using namespace std;
int cnt[15];
void solve(){
	for (int i = 0;i < 10;i++) cnt[i] = 0;
	string s; cin >> s;
	for (char c : s){
		if (c >= '0' && c <= '9') cnt[c - '0']++;
	}for (int i = 9;i >= 0;i--){
		while (cnt[i]--) cout << i;
	}cout << "\n";
}int main(){
    # ifdef FILE
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    # endif
    # ifdef mulq
    int T; cin >> T;
    while (T--) solve();
    # else
    solve();
    # endif
    return 0;
}
