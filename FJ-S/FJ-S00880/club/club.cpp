#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#define freeorphan freopen
#define endl '\n'
using namespace std;
using ll = long long;
ll t, n, mx, ind, d[4];

struct dep{
	ll st, node;
}seq[4];

bool cmp(dep a, dep b){
	return a.st > b.st;
}

int main(void){
	freeorphan("club.in", "r", stdin);
	freeorphan("club.out", "w", stdout); 
	cin >> t;
	while(t--){
		memset(d, 0, sizeof d);
		mx = 0;
		d[1] = 0, d[2] = 0, d[3] = 0;
		cin >> n;
		for(ll i=1; i<=n; ++i){
			seq[1].node = 1;
			seq[2].node = 2;
			seq[3].node = 3;
			cin >> seq[1].st >> seq[2].st >> seq[3].st;
			sort(seq+1, seq+4, cmp);
			for(int c=1; c<=3; ++c){
				if(d[seq[c].node]+1 <= n/2){
					++d[seq[c].node];
					mx += seq[c].st;
					break;
				}
			}
		}
		cout << mx << endl;
	}
	return 0;
}

/*
11/01 14:24 ccf can you make T2 easier plz plz plz
11/01 14:30 the screen is too dirty
            Ren5Jie4Di4Ling5% Ren5Jie4Di4Ling5% Ren5Jie4Di4Ling5%
            #Shang4Shan3Ruo6Shui4 #Shang4Shan3Ruo6Shui4 #Shang4Shan3Ruo6Shui4 
11/01 16:08 keep this version for sure
11/01 18:27 last: geogebra is so interesting
            ccf i beg you for 20pts i dont want to get nothing QwQ
exp. 0~20pts

wo3cong2nan2ji2lai2 zui4xi3huan1chi1shi3
ling2gan3gu1gua1ca1 gu1gu1you4ga2ga2
xiang2zu3ge4yue4dui4 quan2dou1bu2shi4ren2
xiang3cheng2wei2ren2lei4 shen2ren2ba2wo3hei1

subscribe Astralyn_S (^-^) (FJ-S00880 / FJ-J00987)
*/
