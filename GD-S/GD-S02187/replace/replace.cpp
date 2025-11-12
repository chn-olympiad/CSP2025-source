#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q;
vector<int> kmp[N];
struct rep{
	string s1, s2;
	int len;
	vector<int> kmp;
}re[N];
string s[N][3], t[N][3];
bool cmp(rep a, rep b){
	if (a.len == b.len){
		if (a.s1 == b.s1){
			return a.s2 < b.s2; 
		}
		return a.s1 < b.s1;
	}
	return a.len < b.len;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> re[i].s1 >> re[i].s2;
		re[i].len = re[i].s1.length();
		re[i].s1 = " " + re[i].s1;
		re[i].s2 = " " + re[i].s2;
		re[i].kmp.reserve(re[i].len + 1);
		re[i].kmp[1] = 0;
		for (int j = 0, k = 2; k <= re[i].len; ++k){//kmp
			while(j > 0 && re[i].s1[j + 1] != re[i].s1[k]){
				j = re[i].kmp[j];
			}
			if (re[i].s1[j + 1] == re[i].s1[k]){
				++j;
			}
			re[i].kmp[k] = j;
		}
	}
	sort(re + 1, re + n + 1, cmp);
	for (int i = 1; i <= q; ++i){
		cin >> t[i][1] >> t[i][2];
		t[i][1] = "@" + t[i][1] + "!", t[i][2] = "@" + t[i][2] + "!";
	}
	for (int i = 1; i <= q; ++i){
		int len1 = t[i][1].length(), len2 = t[i][2].length();
		if (len1 != len2){
			cout << "0\n";
			continue;
		}
		int l = 0, r = n + 1;
		while(l < n && t[i][1][l + 1] == t[i][2][l + 1]){
			++l;
		}
		while(r > 1 && t[i][1][r - 1] == t[i][2][r - 1]){
			++r;
		}
		int ans = 0;
		for (int j = 1; j <= n; ++j){//Ã¶¾Ùn¸öÌæ»» 
			int len_n = t[i][1].length();
			for (int l = 0, k = 1; k <= len_n; ++k){//kmp
				while(l > 0 && re[j].s1[l + 1] != t[i][1][k]){
					l = re[j].kmp[l];
				}
				if (re[j].s1[l + 1] == t[i][1][k]){
					++l;
				}
				if(l == re[j].len){
					for (int ii = k - re[j].len + 1; ii <= k; ++ii){
						swap(re[j].s2[ii - k + re[j].len], t[i][1][ii]);
					}
					if (t[i][1] == t[i][2]){
						++ans;
					}
					for (int ii = k - re[j].len + 1; ii <= k; ++ii){
						swap(re[j].s2[ii - k + re[j].len], t[i][1][ii]);
					}
				} 
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
