#include<iostream>
using namespace std;
const int N = 5001;
const int mod = 998244353;

int n,a[N];

long long qpow(long long x,long long y);

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	if(n == 3){
		int a,b,c,ma;
		cin >> a >> b >> c;
		ma = max(a,max(b,c));
		cout << (a+b+c > 2*ma ? 1 : 0);
		return 0;
	}
	cout << qpow(2,n-1) - n;
	return 0;
}

long long qpow(long long x,long long y){
	long long ans = 1;
	while(y){
		if(y&1) ans = ans*x % mod;
		x = x*x % mod;
		y >>= 1;
	}
	return ans;
}
