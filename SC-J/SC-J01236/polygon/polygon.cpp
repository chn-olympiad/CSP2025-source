#include<bits/stdc++.h>
#define _all(i,a,b) for(int i = a; i <= b; i++)
#define __all(i,a,b) for(int i = a; i < b; i++)
#define r_all(i,a,b) for(int i = a; i >= b;i--)
#define vt vector<int>
#define vl vector<LL>
using namespace std;
using LL = long long;
const int MOD = 998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n;LL ans = 0;
	cin>>n;
	vt a(n+1);
	int fll = 0;
	_all(i,1,n) cin>>a[i],fll = max(fll,a[i]);
	auto F = [](int r,int k) -> LL{
		LL ret = 1;
		_all(i,1,k) ret *= r,r --;
		return ret;
	};
	if(fll == 1){ //maxa[i] <= 1
		_all(i,3,n) (ans += F(n,i) / F(i,i-1)) %= MOD;
		return printf("%lld",ans),0;
	}
	_all(y,1,(1 << n)){
		int cnt = 0 ,sum = 0,maxx = 0,k = y,j = 1,fl = 0;
		while(k > 0 and !fl){
			if(k % 2 == 1 and ++cnt >= 3) fl = 1;
			k /= 2;
		}
		if(!fl) continue;
		k = y;
		while(k > 0){
			if(k % 2 == 1) sum += a[j] , maxx = max(maxx , a[j]);
			k /= 2, j ++;
		}
		if(maxx * 2 < sum) ans ++;
	}
	return printf("%lld\n",ans),0; //freopen!
}
//O(2^n) 50pt
//freopen!

