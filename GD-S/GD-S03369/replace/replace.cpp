#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define Sz(a) a.size()
const int N = 2e5 + 10;
using ll = long long;
void ckmax(ll &x,ll y){
	x = max(x, y); return;
}
int n, q;
string a[N], b[N];
void calc(){
	int res = 0; string A, B; cin >> A >> B;
	int tp = 0;
	while(A[tp] == B[tp]) tp++;
	rep(i,1,n){
		if(A == a[i] && B == b[i]){
			res++; continue;
		}
		int k = Sz(a[i]), m = Sz(b[i]); int o1 = 0, o2 = 0;
		rep(j,0,k-1){
			if(tp + j >= Sz(A)){
				o1 = 1; break;
			}
			if(A[tp + j] != a[i][j]){
				o1 = 1; break;
			}
		}
		rep(j,0,m-1){
			if(tp + j >= Sz(B)){
				o2 = 1; break;
			}
			if(B[tp + j] != b[i][j]){
				o2 = 1; break;
			}
		}
		if(!o1 && !o2){
			int l = tp + k, r = tp + m, fl = 0;
			rep(o,0,Sz(A)-l){
				if(A[l + o] != B[r + o]){
					fl = 1; break;
				}
			}
			if(!fl) res++;
		}
	}
	cout << res << "\n"; return;
}
void solve(){
	cin >> n >> q;
	rep(i,1,n){
		cin >> a[i] >> b[i];
	}
	while(q--){
		calc();
	}
	return;
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

