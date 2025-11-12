#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#define int long long

using namespace std;

const int MOD = 998244353,N = 520;
int n,m,c[N],c1[N];
string s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		c1[i] = c[i];
	}
	if(n <= 11){
		int cnt = 0,cs = 1,ded = 0,sus = 0;
		for(int i = 1;i <= n;i++){
			cs *= i;
		}
		while(cs--){
			ded = sus = 0;
			for(int i = 1;i <= n;i++){
				if(ded >= c1[i]){
					ded++;
					continue;
				}
				if(s[i-1] == '1') sus++;
				else ded++;
			}
			if(sus >= m) cnt++;
			next_permutation(c1+1,c1+n+1);
		}
		cout << cnt;
		return 0;
	} 
	cout << 0;

	return 0;
}
