#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define endl '\n'

const int N = 1e6+5;
const int MOD = 10;
string s;
int a[N];

bool cmp(int x,int y) {
	return x > y;
}

void solve() {
	cin >> s;
	int j = 0;
	for(int i=0; i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[j] = s[i]-'0';
			j++;
		}
	}
	
	sort(a,a+j,cmp);
	for(int i=0; i < j; i++) {
		cout << a[i];
	}
    return;
}

signed main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}
