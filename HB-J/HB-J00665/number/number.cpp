#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int number[1000005];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ll l = s.size();
	for(ll i = 1;i <= l;i ++) {
		number[i] = -1;
	}
	ll cnt = 0;
	for(ll i = 0;i < l;i ++) {
		if(s[i] >= '0' && s[i] <= '9') {
			cnt += 1;
			number[cnt] = s[i] - '0';
		}

	}
	int maxnumber =  -1;
	ll numberi = 0x3f;	
	for(ll i = 1;i <= cnt;i ++) {
		for(ll j = 1;j <= cnt;j ++)
			if(number[j] > -1)
				if(maxnumber < number[j]) {
					maxnumber = number[j];
					numberi = j;
				}
		cout << maxnumber;
		number[numberi] = -1;
		numberi = 0x3f,maxnumber =  -1;
	}
	return 0;
}
