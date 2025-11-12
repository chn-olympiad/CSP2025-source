#include <bits/stdc++.h> 

using namespace std;

const int N = 1e4 + 5;

struct node {
	int a, b;
}a[N], b[N], t[N], m[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q ;
	for(int i = 1;i <= n;i++) {
		string s1, s2;
		cin >> s1 >> s2 ;
//		cout << s1 << s2<<endl;
		for(int j = 0;j <= s1.size();j++) {
			if(s1[j] == 'b') {
				a[i].a = j, a[i].b = s1.size() - j - 1;
				break;
			}
		}
		for(int j = 0;j <= s2.size();j++) {
			if(s2[j] == 'b') {
				b[i].a = j, b[i].b = s2.size() - j - 1;
				break;
			}
		}
	}
	for(int i = 1;i <= q;i++) {
		string s1, s2;
		cin >> s1 >> s2 ;
		for(int j = 0;j <= s1.size();j++) {
			if(s1[j] == 'b') {
				t[i].a = j, t[i].b = s1.size() - j - 1;
			}
		}
		for(int j = 0;j <= s2.size();j++) {
			if(s2[j] == 'b') {
				m[i].a = j, m[i].b = s2.size() - j - 1;
			}
		}
		
		int ans = 0;
		for(int j = 1;j <= n;j++) {
			if(a[j].a <= t[i].a && a[j].b <= t[i].b && t[i].a - a[j].a + b[j].a == m[i].a && t[i].b - a[j].b + b[j].b == m[i].b)
				ans++;
		}
		cout << ans << endl ;
	}
}
