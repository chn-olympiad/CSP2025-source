#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
/**
 *  Newman
 *  4/2=0
 *  sum  <i/2
 *
 */
// 8 10 11
using namespace std;
typedef int   ll;
int tpu(int a, int b, int c) {
	if (a > b) {
		if (b < c && c > a) {
			return c;
		} else if (b < c && c < a) {
			return a;
		} else if (b > c && c < a) {
			return b;
		}
	} else {
		if (b > c && c < a) {
			return a;
		} else if (b > c && c > a) {
			return c;
		} else if (b < c && c > a) {
			return b;
		}
	}
}

int very_max(int z, int x) {
	return max(z, x);
}

ll very_setzero(ll& l) {
	l = 0;
	return l;
}

bool lco_lim(ll lz, int ps) {
	return lz <= ps / 2;
}

bool lco_lpm(ll lz, int ps) {
	return lz < ps / 2;
}
int fl;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	iostream::sync_with_stdio(false);
	int t, n, man[20000][3] = {}, zoom[100] = {};
	cin >> t;
	for (int i = 0; i < t; i++) {
		fl = i;
		ll sum = 0;
		cin >> n;
		for (int l = 0; l < n; l++) {
			for(int p=0;p<4;p++){
				zoom[p] = 0;
			}
			cin >> man[l][0] >> man[l][1] >> man[l][2];
			//4 2 1
			sum += max(max(man[l][0], man[l][1]), max(man[l][1], man[l][2]));
			int pl = 0;
			pl = man[l][0] > man[l][1] ? 0 : 1;
			if (pl) {
				pl = man[l][1] > man[l][2] ? 1 : 2;
			} else {
				pl = man[l][0] > man[l][2] ? 0 : 2;
			}
			zoom[pl]++;
		}
		bool dicker = true;
		for (int j = 0; j < 3; j++) {
			if (lco_lim(zoom[j], i / 2)) {
				cout << sum << "\n";
				break;
			} else {
				dicker = false;
				break;
			}
		}
		if (dicker == false) {
			ll sum = 0;
			for (int z = 0; z < fl / 2; z++) {
				sum += tpu(man[z][0], man[z][1], man[z][2]);
			}
			for (int z = fl / 2; z < fl; z++) {
				sum += max(max(man[z][0], man[z][1]), max(man[z][1], man[z][2]));
			}
			cout << sum << "\n";
			break;
		}
	}
}
/*

if(!dicker){
ll sum = 0;
for(int z=0;z<fl/2;z++){
sum += tpu(man[z][0],man[z][1],man[z][2]);
}
for(int z=fl/2;z<fl;z++){
sum += max(max(man[z][0],man[z][1]),max(man[z][1],man[z][2]));
}
cout<<sum<<"\n";
continue;
}

*/