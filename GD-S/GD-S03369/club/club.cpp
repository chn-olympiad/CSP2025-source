#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
const int N = 3e5 + 10;
using ll = long long;
struct Z{
	int a, b, c;
}E[N];
int calc(int x){
	return (E[x].a - max(E[x].b, E[x].c));
}
bool cmp(Z x,Z y){
	return (x.a - max(x.b, x.c)) > (y.a - max(y.b, y.c));
}
struct G{
	int w;
	bool operator <(const G &x)const{
		return calc(x.w) < calc(w);
	}
};
void ckmax(ll &x,ll y){
	x = max(x, y); return;
}
int n; ll res;
void calc(){
	sort(E+1,E+1+n,cmp); std::priority_queue<int> q; int V = n / 2, tpB = 0, tpC = 0, o = 0; ll val = 0;
	rep(i,1,V){
		q.push(i); val += E[i].a;
	}
	rep(i,V+1,n){
		int id = q.top(); q.pop();
		auto [a, b, c] = E[id]; auto [A, B, C] = E[i];
		if(calc(id) < calc(i)){
			q.push(i); val += A - a + max(b, c); 
			if(b == c){
				tpB++, tpC++, o++;
			}
			if(b > c){
				tpB++;
			}
			if(c > b){
				tpC++;
			}
		}
		else{
			q.push(id); val += max(B, C);
			if(B == C){
				tpB++, tpC++, o++;
			}
			if(B > C){
				tpB++;
			}
			if(C > B){
				tpC++;
			}
		}
	}
	while(!q.empty()){
		int id = q.top(); q.pop();
		auto [a, b, c] = E[id];
		if(b > c){
			if(b > a){
				if(tpB < n / 2){
					val += b - a; tpB++;
				}
				else if(o){
					tpC++, tpB--, o--;
					val += b - a; tpB++;
				}
			}
			else if(c > a){
				if(tpC < n / 2){
					val += c - a; tpC++;
				}
				else if(o){
					tpB++, tpC--, o--;
					val += c - a; tpC++;
				}
			}
		}
		else{
			if(c > a){
				if(tpC < n / 2){
					val += c - a; tpC++;
				}
				else if(o){
					tpB++, tpC--, o--;
					val += c - a; tpC++;
				}
			}
			else if(b > a){
				if(tpB < n / 2){
					val += b - a; tpB++;
				}
				else if(o){
					tpC++, tpB--, o--;
					val += b - a; tpB++;
				}
			}
		}
	}
	ckmax(res, val); return;
}
void solve(){
	cin >> n; res = 0;
	rep(i,1,n){
		int a, b, c; cin >> a >> b >> c; 
		E[i] = {a, b, c};
	} 
	calc(); 
	rep(i,1,n){
		swap(E[i].a, E[i].b);
	}
	calc();
	rep(i,1,n){
		swap(E[i].a, E[i].c);
	}
	calc();
	cout << res << "\n";
	return;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
