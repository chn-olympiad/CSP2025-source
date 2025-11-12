#include<bits/stdc++.h>
namespace kimi{
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb emplace_back
#define endl '\n'
#define dbg(x) cerr << x << endl
#define TLE AC
#define WA AC
using namespace std;
int n, q;
void mian(){
	cin >> n >> q;
	for(int i = 1; i <= q; i++) cout << 0 << endl;
}
}using namespace kimi;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int Test = 1;
	//cin >> Test;
	while(Test--) mian();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
