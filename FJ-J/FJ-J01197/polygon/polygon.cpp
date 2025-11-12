#include<bits/stdc++.h>
using namespace std;
long long _n,_woodR[5010],_mod=998244353,_vis[5010], _flag;
long long _tmp=1, sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_n;
	for(long long i=1; i<=_n; i++) {
		cin>>_woodR[i];
		if(_woodR[i]>1){
			_flag=1;
		}
	}
	if(_n<=3) {
		if(_n==3) {
			long long _mx=max(max(_woodR[1],_woodR[2]),_woodR[3]),_sum=_woodR[1]+_woodR[2]+_woodR[3];
			if(_sum>2*_mx) {
				cout<<1;
			} else {
				cout<<0;
			}
		} else {
			cout<<0;
		}
	} else {
		if((!_flag)) {
			for(int i=3; i<=_n; i++) {
				for(int j=0; j<i; j++) {
					_tmp=_tmp*(_n-j)/(j+1);
				}
				sum += _tmp;
				_tmp = 0;
				sum %= _mod;
			}
			cout<<sum;
		}
	}
	return 0;
}
