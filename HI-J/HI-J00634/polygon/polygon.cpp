#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5005],c[5005],ans;
const long long mod = 998244353;
void dfs(long long x,long long b,long long num){
	b++;
	num += a[x];
	for(int i = x+1;i <= n;i++){
		dfs(i,b,num);
	}
	if(num > a[x] * 2 && b >= 3) ans++;
}
int main(){
	cin >> n;
	for(int i = 1;i<= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) dfs(i,0,i);
	cout << ans % mod;
	return 0;
}
