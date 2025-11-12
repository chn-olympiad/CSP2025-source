#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5020;const ll mod = 998244353;
ll n,arr[N],pow2[N],f[N][N],ans;
bool visf[N][N];
inline int getf(int i,int j){
	if(i == 0) return 0;
	if(visf[i][j]) return f[i][j];
	visf[i][j] = 1;f[i][j] = 0;
	if(arr[i] > j) (f[i][j] += pow2[i-1]) %= mod;
	else (f[i][j] += getf(i-1,j-arr[i])) %= mod;
	(f[i][j] += getf(i-1,j)) %= mod;
	return f[i][j];
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	pow2[0] = 1;for(int i = 1;i < N;++i) pow2[i] = pow2[i-1]*2%mod;
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> arr[i];
	}sort(arr+1,arr+1+n);
	for(int i = 1;i <= n;++i) (ans += getf(i-1,arr[i])) %= mod;
	cout << ans << "\n";
	return 0;
}