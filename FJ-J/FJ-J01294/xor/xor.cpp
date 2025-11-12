#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5*1e5 + 10;
ll a[N];
int main(){
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	ll n, k;
	scanf("%lld%lld", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	if(n == 1 && k == 0){
		if(a[1] == 0) cout << "1";
		else cout << "0";
	}
	else if(n <= 2 && k == 0){
		int aa = a[1], bb = a[2];
		int cc = 0;
		cc = max(aa, bb);
		bool f = 0;
		while(cc){
			int ta = aa % 2;
			int tb = bb % 2;
			if(ta != bb){
				f = 1;
			}cc /= 2;
		}if(f && (aa == 0 || bb == 0)) cout << "1";
		else if(!f) cout <<"2";
		else cout << "0";
	}
	return 0;
}
