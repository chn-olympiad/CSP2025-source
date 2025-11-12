#include<bits/stdc++.h>
using namespace std;
#define cfalse cin.tie(0)->sync_with_stdio(0)
const int md = 998244353;
const int maxn = 2e5 + 5;
int n;
int arr[maxn];
int bully(int x, int maxx, int num, int cnt){
	int res = 0;
	if(x == n && num >= 3 && cnt > 2 * maxx){
		res++;
//		cout << s << endl;
	}
	if(x == n)return res;
	res += bully(x + 1, max(maxx, arr[x]), num + 1, cnt + arr[x]);
	res %= md;
	res += bully(x + 1, maxx, num, cnt);
	res %= md;
	
	return res % md;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cfalse;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}
	int ans = 0;
	ans += bully(0, 0, 0, 0);
	ans %= md;
//	ans += bully(0, arr[0], 1, arr[0]);
	ans %= md;
	cout << ans;
	return 0;
}
