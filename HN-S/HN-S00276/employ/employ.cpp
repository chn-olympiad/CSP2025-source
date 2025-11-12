#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NR = 505; 
int n,m;
string s;
int a[NR];
int p[NR];
int ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) p[i] = i;
	do{
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(i - cnt - 1 >= a[p[i]]) continue;
			if(s[i] == '1') cnt++;
		}
		if(cnt >= m) ans++;
	}while(next_permutation(p + 1,p + n + 1));
	cout << ans;
	return 0;
}

