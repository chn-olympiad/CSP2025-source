#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long 
#define pii pair<int, int>
#define mse(x, y) memset(x, y, sizeof x)
#define mcp(x, y) memcpy(x, y, sizeof x)
#define viclear(x) vector<int>().swap(x)
#define vpiiclear(x) vector<pii>().swap(x)
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define drep(x, r, l) for(int x = r; x >= l; x--)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
using namespace std;

const int MAXN = 1e5 + 5;
int n, a[MAXN], b[MAXN], c[MAXN], T[3], Sum;
priority_queue<int> q;

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	FASTIO;
	int _;
	cin >> _;
	while(_--){
		while(q.size()) q.pop();
		cin >> n, Sum = T[0] = T[1] = T[2] = 0;
		rep(i, 1, n) cin >> a[i] >> b[i] >> c[i];
		rep(i, 1, n){
			if(a[i] >= b[i] && a[i] >= c[i]) T[0]++, Sum += a[i];
			else if(b[i] >= a[i] && b[i] >= c[i]) T[1]++, Sum += b[i];
			else T[2]++, Sum += c[i];
		}
		int num = 0;
		if(T[0] > n / 2){
			num = T[0] - n / 2;
			rep(i, 1, n){
				if(a[i] >= b[i] && a[i] >= c[i]) q.push(max(b[i], c[i]) - a[i]);
				else if(b[i] >= a[i] && b[i] >= c[i]) ;
				else ;
			}
		}
		else if(T[1] > n / 2){
			num = T[1] - n / 2;
			rep(i, 1, n){
				if(a[i] >= b[i] && a[i] >= c[i]) ;
				else if(b[i] >= a[i] && b[i] >= c[i]) q.push(max(a[i], c[i]) - b[i]);
				else ;
			}
		}
		else if(T[2] > n / 2){
			num = T[2] - n / 2;
			rep(i, 1, n){
				if(a[i] >= b[i] && a[i] >= c[i]) ;
				else if(b[i] >= a[i] && b[i] >= c[i]) ;
				else q.push(max(a[i], b[i]) - c[i]);
			}
		}
		while(num) Sum += q.top(), q.pop(), num--;
		cout << Sum << '\n';
	}
    return 0;
}

