#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a; i<=b; ++i)
#define F_(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define pii pair<int,int>
#define fr first
#define sc second
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+10; const ull B = 13331;
int n,q;
string s[2][N],t[2];
ull qhs[2][N],hhs[2][N],pw[N];
map<pair<ull,ull>,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0] = 1;
	F(i,1,N-1) pw[i] = pw[i-1]*B;
	
	cin >> n >> q;
	F(i,1,n) cin >> s[0][i] >> s[1][i];
	
	F(i,1,n){
		ull r1 = 0, r2 = 0;
		for (int j=0; j<s[0][i].size(); ++j){
			r1 = r1*B + s[0][i][j];
		}
		for (int j=0; j<s[1][i].size(); ++j){
			r2 = r2*B + s[1][i][j];
		}
		mp[{r1,r2}]++;
	} 
	while (q--){
		cin >> t[0] >> t[1];
		
		if (n >= 100000){
			cout << "0\n";
			continue;
		} 
		t[0] = " "+t[0], t[1] = " "+t[1];
		F(o,0,1){
			for (int i=1; i<=t[0].size()-1; ++i) qhs[o][i] = qhs[o][i-1]*B + t[o][i];
			for (int i=t[0].size()-1; i>=1; i--) hhs[o][i] = hhs[o][i+1]*B + t[o][i];
		}
		
		ll ans = 0;
		for (int i=1; i<=t[0].size()-1; ++i){
			if (qhs[0][i-1] != qhs[1][i-1]) break;
			for (int j=t[0].size()-1; j>=i; j--){
				if (hhs[0][j+1] != hhs[1][j+1]) break;
				ll r1 = qhs[0][j]-qhs[0][i-1]*pw[j-i+1], r2 = qhs[1][j]-qhs[1][i-1]*pw[j-i+1];
				ans += mp[{r1,r2}];
			}
		}
		cout << ans << "\n";
		
		F(o,0,1){
			for (int i=1; i<=t[0].size(); ++i) qhs[o][i] = 0;
			for (int i=t[0].size(); i>=1; i--) hhs[o][i] = 0;
		}
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
