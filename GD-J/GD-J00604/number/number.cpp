#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 1e6 + 6;
int sum[N],tot;
void solve(){
	string s;
	cin >> s;
	for(auto &v : s)
		if(v >= '0' && v <= '9')
			sum[++tot] = v - '0';
	sort(sum + 1,sum + 1 + tot,greater<int> ());
	for(int i = 1;i <= tot; i++)
		cout << sum[i];
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	int T = 1;
	while(T--)
		solve();
	return 0;
} 
