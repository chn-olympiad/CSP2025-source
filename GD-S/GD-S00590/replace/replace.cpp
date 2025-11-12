#include <bits/stdc++.h>
using namespace std;
#define int long long
struct ex{
	string dif;
	int len;
	char s;
}a[200005];
bool f(ex c, ex v){
	return c.len > v.len;
}

string st, en, df;

signed main(){

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> st >> en;
		int l = 0, r = st.length() - 1;
		for(; l < st.length(); l++) if(st[l] != en[l])break;
		for(; r >= 0; r--) if(st[r] != en[r])break;
		char sll = st[l];
		string difll;
		for(int i = l; i <= r; i++){
			difll += st[i] - en[i] + '0';
		}
		a[i] = {difll, difll.length(), sll};
	}
	sort(a, a + n, f);
	
	while(q--){
		cin >> st >> en;
		int l = 0, r = st.length() - 1;
		for(; l < st.length(); l++) if(st[l] != en[l])break;
		for(; r >= 0; r--) if(st[r] != en[r])break;
		
		for(int i = l; i <= r; i++){
			df += st[i] - en[i] + '0';
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(st[l] == a[i].s && df == a[i].dif) ans ++;
		}
		cout << ans << endl;
	}
	
	return 0;
} 
