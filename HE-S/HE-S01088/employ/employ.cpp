#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M = 510 , mod = 998244353;
int n , m , dif[M] , c[M] , p[M] , ans;
string s;

signed main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	cin>>n>>m>>s;
	for(int i = 1; i <= n; ++i)
		cin>>c[i] , p[i] = i , dif[i] = s[i - 1] == '0';
	do{
		int cur = 0 , cnt = 0;
		for(int i = 1; i <= n; ++i){
			if(cur >= c[p[i]] || dif[i]) ++cur;
			else ++cnt;
		}
		ans += cnt >= m;
	} while(next_permutation(p + 1 , p + 1 + n));
	cout<<ans<<'\n';

	return 0;
}
// i can't solve it at all
// 10pts is for me

// QAQ
// so difficult
// regret && sorrow
// <220 for grade 1 at senior high is too low