#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
struct node{
	string s, ss, sss;
}a[200005];
node b[200005];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n;i++){
		cin >> a[i].s >> a[i].ss;
	}
	for(int i = 1; i <= q; i++){
		cin >> b[i].s >> b[i].ss;
	}
	for(int i = 1; i <= q; i++){
		if(b[i].s.size() != b[i].ss.size()){
			cout << 0 << endl;
			continue;
		}
		ans = 0;
		for(int j = 1; j <= b[i].s.size(); j++){
			b[i].sss = b[i].s;
			if(a[i].s[j] == b[i].s[j]){
				for(int k = j; k <= a[i].ss.size() + j - 1; k++){
					b[i].sss[k] = a[i].ss[k];
				}
				if(b[i].sss == b[i].ss){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
