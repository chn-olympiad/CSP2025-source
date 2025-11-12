#include<bits/stdc++.h>
using namespace std;
const long long N = 998244353;
long long a[1000005], vis[1000005];
long long n, ans;
void f(long long x, long long cnt, int t){
	if(x == n + 1 ){
		if(cnt < 3){
			return ;
		}
		long long sum = 0;
		for(int i = 1; i <= n ;i++){
			if(vis[i] == 1 ){
				sum += a[i];
			}
		}
		if(sum  > a[t] * 2){
			ans = (ans + 1) % N;
		}
		return ;
	}
	int l = t;
	vis[x] = 1;
	if(a[t] < a[x]){
		l = x;
	}
	f(x + 1, ++cnt, l);
	
	vis[x] = 0;
	f(x + 1, cnt, t);
	
}


int main(){
	freopen("polygon.in", "r",stdin);
	freopen("polygon.out", "w",stdout);
	cin >> n ;
	for(int i = 1 ;i <= n ;i++){
		cin >> a[i];
	}
	
	f(1, 0, 0);
	
	cout << ans;
	return 0;
}
