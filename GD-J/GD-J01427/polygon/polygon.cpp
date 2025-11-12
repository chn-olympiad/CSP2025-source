#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int mod = 998244353;
int n,a[N];
long long ans = 0;
int f[2][N];//f[i]表示和为i的方案数 
long long c[N * 2];
int maxf = 1;
int lowbit(int x){
	return x & (-x);
}
void add(int x,long long k){
	while(x <= N){
		c[x] = (c[x] + k) % mod;
		x += lowbit(x);
	}
}
long long merge(int x){
	long long ans = 0;
	while(x > 0){
		ans = (ans + c[x]) % mod;
		x -= lowbit(x);
	}
	return ans;
}
long long kuai(int a,int b){
	if(b == 0) return 1;
	long long ans = 1;
	while(b){
		if(b & 1){
			ans = (ans * a)% mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	n = 5000;
//	add(1,1);
//	add(1,2);
//	cout << merge(4);
//	add(2,2);
//	cout << merge(2);
	memset(f,0,sizeof(f));
	cin >> n;
	f[0][0] = 1;
	f[1][0] = 1;
	int op = 1;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	//cin >> a[1];
	//f[a[1]] = 1;
//	for(int j = 0;j <= maxf;j++){
//		if(j + a[1] > 5000) break;
//		f[op][j + a[1]] = (f[op][j + a[1]] + f[op ^ 1][j]) % mod;
//		maxf = max(maxf,j + a[1]);
//		add(j + a[1],f[op ^ 1][j]);
//	}
//	f[1][0] = 1;
	
	for(int i = 1;i <= n;i++){
		op ^= 1;
		//cout << maxf << endl;
		for(int j = 0;j <= maxf;j++){
			f[op][j] = f[op ^ 1][j];
			//cout << f[op^1][j] << ' ';
		}
//		cout << endl;
//		for(int j = 0;j <= maxf;j++){
//			cout << c[j] << ' ';
//		}
		//cout << endl;
		//cin >> a[i];
		//cout << merge(a[i]) << endl;
		ans = (ans + kuai(2,i - 1) - merge(a[i]) - 1 + mod) % mod;
		//cout << ans << endl;
		int tmp = maxf;
		for(int j = 0;j <= tmp;j++){
			if(j + a[i] > 5000) break;
			f[op][j + a[i]] = (f[op][j + a[i]] + f[op ^ 1][j]) % mod;
			maxf = max(maxf,j + a[1]);
			add(j + a[i],f[op ^ 1][j]);
		}
		
	}
	cout << ans << endl;
	return 0;
}
