#include <bits/stdc++.h>
using namespace std;
const int M = 2 * 1e6 + 10,N = 1e3 + 15;
int t,n,q;
string a[N],b[N];
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
  freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
   cin >> n >> q;
   for(int i = 1; i <= n; i++) {
	   cin >> a[i] >> b[i];
   }
   while(q--) {
	    string x,y;
	    cin >> x >> y;
	    long long sum = 0,cnt = 0;;
	    for(int i = 1; i <= n; i++) {
			string t = x;
			for(int j = 0; j < x.size(); j++) {
				t = x;
				if(t[j] == a[i][0]) {
					
					int f = 0;
					for(int k = j; k < j + a[i].size(); k++) {
						if(t[k] != a[i][k - j]) {
							f = 1;
							break;
						}
						t[k] = b[i][k - j];
					}
					if(t != y) f = 1;
					if(f == 0) cnt++;
				}
		     }
		}
		cout << cnt << '\n';
	}
  return 0;
}/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
