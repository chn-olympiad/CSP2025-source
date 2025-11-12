#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAXN = 2e5+5, MAXL = 5e6+5;
const ull MOD = 998244353, B = 13;

ull QuickPow(ull a, ull b){
	ull res = 1;
	while (b){
		if (b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	} return res;
}

int n, q, ls, rs; ull inv; ll ans;
ull p13[MAXL];
string s[MAXN][3];
string t1, t2;
vector <ull> pre1, pre2, pre3, pre4;

ull get(int lhs, int rhs, int typ){
	if (typ == 1) return (pre1[rhs]-pre1[lhs-1]*p13[rhs-lhs+1]%MOD+MOD)%MOD;
	if (typ == 2) return (pre2[rhs]-pre2[lhs-1]*p13[rhs-lhs+1]%MOD+MOD)%MOD;
	if (typ == 3) return (pre3[rhs]-pre3[lhs-1]*p13[rhs-lhs+1]%MOD+MOD)%MOD;
	return (pre4[rhs]-pre4[lhs-1]*p13[rhs-lhs+1]%MOD+MOD)%MOD;
}

int main(){
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	p13[0] = 1; for (int i=1; i<=5e6; i++) p13[i] = (p13[i-1]*B)%MOD;
	for (int i=1; i<=n; i++) cin >> s[i][1] >> s[i][2];
	for (int i=1; i<=q; i++){
		cin >> t1 >> t2; ans = 0;
		int len = t1.size(); ls = 0; rs = len+1;
		for (int j=1; j<=len; j++){
			if (t1[j-1] == t2[j-1]) ls = j;
			else break;
		}
		for (int j=len; j>=1; j--){
			if (t1[j-1] == t2[j-1]) rs = j;
			else break;
		} ls++; rs--; //cout << ls << " " << rs << "\n";
		pre3.resize(len+1); pre3[0] = 0;
		pre4.resize(len+1); pre4[0] = 0;
		for (int j=1; j<=len; j++) pre3[j] = (pre3[j-1]*B+(ull)(t1[j-1]))%MOD;
		for (int j=1; j<=len; j++) pre4[j] = (pre4[j-1]*B+(ull)(t2[j-1]))%MOD;
		for (int j=1; j<=n; j++){
			pre1.resize(s[j][1].size()+1); pre1[0] = 0;
			pre2.resize(s[j][2].size()+1); pre2[0] = 0;
			for (int k=1; k<=s[j][1].size(); k++) pre1[k] = (pre1[k-1]*B+(ull)(s[j][1][k-1]))%MOD;
			for (int k=1; k<=s[j][2].size(); k++) pre2[k] = (pre2[k-1]*B+(ull)(s[j][2][k-1]))%MOD;
			//for (int k=1; k<=s[j][1].size(); k++) cout << pre1[k] << " "; cout << "\n";
			//for (int k=1; k<=s[j][2].size(); k++) cout << pre2[k] << " "; cout << "\n";
			for (int k=1; k<=s[j][1].size(); k++){
				int lhs = k, rhs = k+(rs-ls+1)-1;
				//cout << j << " " << lhs << " " << rhs << "\n";
				if (rhs > s[j][1].size()) break;
				ll hv1 = get(lhs, rhs, 1), hv2 = get(lhs, rhs, 2);
				ll hv3 = get(ls, rs, 3), hv4 = get(ls, rs, 4);
				if (hv1 != hv3 || hv2 != hv4) continue;
				//cout << "ok1!\n";
				int ls_siz = lhs-1, rs_siz = s[j][1].size()-rhs;
				int lhs1 = 1, rhs1 = ls_siz;
				//cout << lhs1 << " " << rhs1 << "\n";
				if (ls-ls_siz < 1) continue;
				hv1 = get(lhs1, rhs1, 1), hv2 = get(lhs1, rhs1, 2);
				//cout << "ok not out of bound\n";
				if (hv1 != hv2) continue;
				//cout << "ok2!\n";
				lhs1 = rhs+1, rhs1 = s[j][1].size();
				//cout << lhs1 << " " << rhs1 << "\n";
				if (rs+rs_siz-1 > len) continue;
				hv1 = get(lhs1, rhs1, 1), hv2 = get(lhs1, rhs1, 2);
				//cout << "ok not out of bound " << hv1 << " " << hv2 << "\n";
				if (hv1 != hv2) continue;
				//cout << "ok3!\n";
				ans++;	
			}
		} cout << ans << "\n";
	}
	return 0;
}