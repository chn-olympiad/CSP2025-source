// Genshin Impact Start!!

#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5+5;

int n,q;
string s[N][2],t[N][2];
int lens[N],lent[N];
int sm[N];
typedef long long ll;
namespace A {
	ll ans = 0;
	bool check (string t0,string t1,int l,int x) {
		for (int i = l;i < l+lens[x];i++) 
			if (t0[i] != s[x][0][i-l] || t1[i] != s[x][1][i-l]) 
				return 0;
		return 1;
	}
	void solve () {
		for (int _ = 1;_ <= q;_++) {
			ans = 0;
			int len = lent[_];
			string t0 = t[_][0],t1 = t[_][1];
			for (int i = 0;i < len;i++) {
				for (int j = 1;j <= n;j++) {
					if (sm[_] <= i+lens[j] && i+lens[j]  <= len && check(t0,t1,i,j)) 
						//printf("at %d , %d is Ok\n",i,j),
						ans++;
				}
					
				if (t0[i] != t1[i]) break;
			}
			printf("%lld\n",ans);
		}
	}
}
int L1,L2 ;
int main () {
	//freopen("replace2.in","r",stdin);
	//freopen("replace.out","w",stdout);	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;i++) {
		cin >> s[i][0] >> s[i][1];
		lens[i] = s[i][0].size();
		L1 += lens[i];
	}
	for (int i = 1;i <= q;i++) {
		cin >> t[i][0] >> t[i][1];
		lent[i] = t[i][0].size();
		L2 += lent[i];
		sm[i] = lent[i];
		for (int j = lent[i]-1;j >= 0;j--) {
			if (t[i][0][j] == t[i][1][j]) sm[i] = j;
			else break;
		}
	}
	if (L1 <= 2000 && L2 <= 2000) {
		A::solve();
		return 0;
	}
	return 0;	
}
