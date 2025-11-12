#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>
#define debug(x) cerr << #x << ": " << x << "\n"
using namespace std;
int n, q;
pair<string, string> a[200007];
string s, t;
void solve12(){
	while(q--){
		cin >> s >> t;
		s = ' ' + s, t = ' ' + t;
		int st = 1, ans = 0;
		for(int i = 1;i <= s.size();i++){
			for(int j = st;j <= n;j++){
				while(a[j].fi.size() > s.size() - i) st++, j++;
				if(j > n) break;
				int k;
				for(k = 0;k < a[j].se.size();k++)
					if(t[i + k] != a[j].se[k] || s[i + k] != a[j].fi[k]) break;
				if(k != a[j].se.size()) continue;
				string tmp = s;
				for(k = 0;k < a[j].se.size();k++) tmp[i + k] = a[j].se[k];
				if(tmp == t) ans++;
			}
		}
		cout << ans << "\n";
	}
}
void solveB(){
	pii b[200007];
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < a[i].fi.size();j++)
			if(a[i].fi[j] == 'b') b[i].fi = j;
		for(int j = 0;j < a[i].se.size();j++)
			if(a[i].se[j] == 'b') b[i].se = j;
	}
	while(q--){
		cin >> s >> t;
		int sb, tb;
		for(int i = 0;i < s.size();i++)
			if(s[i] == 'b') sb = i;
		for(int i = 0;i < t.size();i++)
			if(t[i] == 'b') tb = i;
		int cha = sb - tb;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(b[i].fi - b[i].se == cha && s.size() - (sb - b[i].fi) >= a[i].fi.size() && sb >= b[i].fi) ans++;
		}
		cout << ans << "\n";
	}
}
signed main(){
	srand(time(0));
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + 1 + n, [](pair<string, string> p1, pair<string, string> p2){
		return p1.fi == p2.fi ? p1.se > p2.se : p1.fi > p2.fi;
	});
	bool B = true;
	int cntB = 0;
	for(int r = 1;r <= min(15, n);r++){
		int ind = rand() % n + 1;
		cntB = 0;
		for(int i = 0;i < a[ind].fi.size();i++){
			if(a[ind].fi[i] == 'b') cntB++;
			if(a[ind].fi[i] != 'a' && a[ind].fi[i] != 'b') B = false;
			if(cntB > 1) B = false;
			if(!B) break;
		}
		if(cntB != 1) B = false;
		if(!B) break;
	}
	if(B) solveB();
	else solve12();
}
