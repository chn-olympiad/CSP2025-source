#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
ll n, k, seq[10000005], cnt=0;

ll xorsum(ll l, ll r){
	// it should be right
	ll ans = 0;
	for(int i=l; i<=r; ++i)
		ans ^= seq[i];
	return ans;
}

int main(void){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(ll i=1; i<=n; ++i)
		cin >> seq[i];
	for(ll i=1, j; i<=n; ++i){
		// special judge
		if(seq[i] == k){
			++cnt;
			continue;
		}
		// extensions
		for(j=1; i+j<=n; ++j) // extend length
			if(xorsum(i, i+j) == k){
				++cnt;
				i += j;
				break;
			}
	}
	cout << cnt << endl;
	return 0;
}

/*
11/01 9:24 start T3 now total used 1h
11/01 9:37 back from T4
11/01 9:50 finally know how xor works
11/01 10:02 why ccf's example got wrong?! 
            there's no endls for every ".in"!
11/01 10:08 checked xor1~4 passed; 
            xor5, 6 wrong answer;
            1.5h left and i'll go to T4 for while
11/01 10:16 greedy algorithm should be right
11/01 10:18 i gonna put xor6.in under the code
            why "endl" appeared in the code
            ok i deleted
11/01 10:25 go to check T1, T2 again
11/01 10:35 back again
11/01 10:53 i wonder why T3 is NOT simulation
            ccf give me 260 -> J2 1= QwQ
11/01 11:01 greedy used too much time
11/01 11:11 give up this problem sorry ccf give me 30pts
exp. 30pts

[只要 1=！1= 就能让我认输！[bgm: It's OI Time!] ] 
subscribe Astralyn_S plz ^-^(FJ-J00987)
*/
