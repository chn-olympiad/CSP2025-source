#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define endl '\n'

const int N = 1e6+5;
const int MOD = 10;

int n,m;
int R,Rpos;
int a[225];

bool cmp(int x,int y) {
	return x > y;
}

void solve() {
	cin >> n >> m;
	for(int i=1; i <= n*m; i++) {
		cin >> a[i];
	}
	R = a[1];
	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i <= n*m; i++) {
		if(a[i] == R) {
			Rpos = i;
			break;
		}
	}
	
	Rpos -= 1;
	int ansn=0,ansm=0;
	if((Rpos/n)%2 == 0) {
		ansn = Rpos/n+1;
		ansm = Rpos%n+1;
	}
	else {
		ansn = Rpos/n+1;
		ansm = n-Rpos%n;
	}
	
	cout << ansn << " " << ansm << endl;
    return;
}

signed main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}
