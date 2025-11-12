#include<bits/stdc++.h>
using namespace std;
int n, q, f, ans;
int lena, lenb;
string a, b, c;

struct str{
	string a, b;
	int l;
}s[200005];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++) {
		cin >> s[i].a >> s[i].b;
		s[i].l = s[i].a.size();
	}
	while(q--) {
		cin >> a >> b;
		lena = a.size(), lenb = b.size();
		if(lena != lenb) {
			cout << "0\n";
			continue;
		}
		for(int i = 0 ; i < lena ; i++) {
			for(int j = 1 ; j <= n ; j++) {
				if(lena - i >= s[j].l) {
					c = a;
					f = 1;
					for(int k = i ; k < i + s[j].l ; k++) {
						if(c[k] == s[j].a[k - i]) {
							c[k] = s[j].b[k - i];
						}
						else {
							f = 0;
							break;
						}
					}
					if(f && c == b) ans++;
//					cout << c << ' ' << b << endl;
				}
			}
		}
		cout << ans << endl;
	}

}

