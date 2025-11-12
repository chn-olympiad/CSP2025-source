#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n,q;
struct node{
	string s1,s2;
} s[N];
bool cmp(node f1,node f2){
	return f1.s1.size() < f2.s1.size();
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i].s1 >> s[i].s2;
	sort(s + 1,s + n + 1,cmp);
	while(q--){
		string t1,t2;
		cin >> t1 >> t2;
		int mx = t1.size(),mi = -1,len = mx;
		for(int i = 0; i < len; i++){
			if(t1[i] != t2[i]){
				mi = i;
				break;
			}
		}
		for(int i = len - 1; i >= 0; i--){
			if(t1[i] != t2[i]){
				mx = i;
				break;
			}
		}
		int ans = 0;
		for(int i = 0; i <= mi; i++){
			string f1 = t1.substr(i,mx - i),f2 = t2.substr(i,mx - i);
			int idx = 1;
			for(int j = mx; j < len; j++){
				f1 += t1[j],f2 += t2[j];
				while(idx <= n && s[idx].s1.size() < j - i + 1) ++idx;
				if(idx > n) break;
				for(int k = idx; s[k].s1.size() == j - i + 1; k++){
					if(f1 == s[k].s1 && f2 == s[k].s2){
						++ans;
					}
				}
			}
		}
		cout << ans << '\n';
	} 
	return 0;
}
