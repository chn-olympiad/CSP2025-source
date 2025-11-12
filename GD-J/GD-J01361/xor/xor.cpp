#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define inl inline
#define rep(i,l,r) for(ri i = l; i <= r; i ++)
#define per(i,r,l) for(ri i = r; i >= l; i ++)
#define N 500005
int n, k;
int a[N], s[N][25], sum;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	rep(i, 1, n){
		cin >> a[i];
		rep(j, 0, 20){
			if(a[i] & (1 << j)) s[i][j] = s[i - 1][j] + 1;
			else s[i][j] = s[i - 1][j];
		}
		sum += a[i];
	}
	if(k == 1){
		cout << sum;
		return 0;
	}
	int l = 1, ans = 0;
	rep(i, 1, n){
		rep(j, l, i){
			int f = 1;
			rep(aa, 0, 20){
				if((s[i][aa] - s[j - 1][aa]) % 2 != ((k & (1 << aa)) != 0)){
					f = 0;
					break;
				}
			}
			if(f == 1){
				ans ++;
			 	l = i + 1;
			 	break;
			} 
		}
	}
	cout << ans;
	return 0;
}

