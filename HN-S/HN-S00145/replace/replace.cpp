#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5 , mod = 1e9 + 7;
typedef long long ll;
string a[N] , b[N];
struct node{
	int c , ls , rs;
}c[N];
bool cmp(node x , node y) {
	return x.c < y.c;
}
int n , q;
int low(int p) {
	int l = 1 , r = n , ans = r;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(c[mid].c >= p) ans = mid , r = mid - 1;
		else l = mid + 1; 
	}
	if(c[ans].c != p) return -1;
	else return ans;
}
int main() {
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++) {
		cin >> a[i] >> b[i];
		int h , p;
		for(int j = 0 ; j < a[i].size() ; j ++) {
			if(a[i][j] == 'b') {
				h = j;
				break;
			}
		}
		for(int j = 0 ; j < b[i].size() ; j ++) {
			if(b[i][j] == 'b') {
				p = j;
				break;
			}
		}
		c[i].c = h - p;
		c[i].ls = h;
		c[i].rs = a[i].size() - p - 1;
	}
	sort(c + 1 , c + n + 1 , cmp);
	while(q --) {
		string s , t;
		cin >> s >> t;
		int len = s.size() , len2 = t.size() , l , r;
		if(len != len2) {
			cout << "0\n"; 
			continue;
		}
		for(int j = 0 ; j < len ; j ++) {
			if(s[j] == 'b') {
				l = j;
				break;
			}
		}
		for(int j = 0 ; j < len2 ; j ++) {
			if(t[j] == 'b') {
				r = j;
				break;
			}
		}
		int ls = l , rs = len - r - 1 , i = low(l - r) , ans = 0;
		//cout << l - r << ' ' << i << '\n';
		if(i == -1) {
			cout << "0\n";
		} else {
			while(c[i].c == l - r && i <= n) {
				if(ls >= c[i].ls && rs >= c[i].rs) ans ++;
				i ++;
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
// csp 2025 rp ++
/*
3 4
ab ba
aba baa
baa aba
abaa aaba
baaa baaa
aba aab
aab aba
*/

