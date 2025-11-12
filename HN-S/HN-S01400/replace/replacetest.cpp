#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
const int N = 5e6 + 5;
typedef long long ll;
typedef unsigned long long ull;
const ull base = 1e8 + 7;
string s[N][2], t[N][2];
vector<ull> has[N][2], hat[N][2];
ull p[N];
int n, q;
ull getHash(vector<ull> &h, int l, int r){
	return h[r] - h[l - 1] * p[r - l + 1]; 
}
void solvebl(){
	for(int i = 1; i <= q; i++){
		if(t[i][0].length() != t[i][1].length()){
			cout << 0 << "\n";
			continue;
 		}
		int ans = 0, len = t[i][0].length();
		int pre = 0, suf = 0;
		while(t[i][0][pre] == t[i][1][pre]){
			pre++;
		}
		while(t[i][0][len - suf - 1] == t[i][1][len - suf - 1]){
			suf++;
		}
//		cout << "t0 = " << t[i][0] << " t1 = " << t[i][1] << "\n";
//		cout << "pre = " << pre << " suf = " << suf << "\n";
		int last = len - suf - 1;
//		cout << "last = " << last << "\n";
		for(int j = 0; j < pre + 1; j++){
			for(int k = 1; k <= n; k++){
				int slen = s[k][0].length();
				if((j + slen > len) || (j + slen <= last)){
					continue;
				}
//				cout << "i = " << i << " j = " << j << " s0 = "<< s[k][0] << " s1 = " << s[k][1] << "\n";
//				cout << "t0 = " << t[i][0].substr(j, slen) << " t1 = " << t[i][1].substr(j, slen) << "\n";
//				if(t[i][0].substr(j, slen) == s[k][0] && t[i][1].substr(j, slen) == s[k][1]){
//					ans++;
//				}
//				cout << getHash(hat[i][0], j, j + slen - 1) << " " << getHash(has[k][0], 0, s[k][0].length() - 1) << "\n";
//				cout << getHash(hat[i][1], j, j + slen - 1) << " " << getHash(has[k][1], 0, s[k][1].length() - 1) << "\n";
				if(getHash(hat[i][0], j, j + slen - 1) == getHash(has[k][0], 0, s[k][0].length() - 1)&& 
				     getHash(hat[i][1], j, j + slen - 1) == getHash(has[k][1], 0, s[k][1].length() - 1)){
					ans++;
				}
//				cout << "ans = " << ans << "\n";
			}
		}
		cout << ans << "\n";
	}
}
void input(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i][0] >> s[i][1];
		int len1 = s[i][0].length();
		int len2 = s[i][1].length();
		has[i][0].resize(len1 + 2);
		has[i][1].resize(len2 + 2);
		ull k = 0;
//		cout << s[i][0] << "\n";
		has[i][0][0] = s[i][0][0];
		for(int j = 1; j < len1; j++){
			has[i][0][j] = has[i][0][j - 1] * base + s[i][0][j];
//			cout << k << " ";
		}
//		cout << "\n";
		has[i][1][0] = s[i][1][0];
		for(int j = 1; j < len2; j++){
			has[i][1][j] = has[i][1][j - 1] * base + s[i][1][j];
//			cout << k << " ";
		}
//		cout << "\n";
	}
	for(int i = 1; i <= q; i++){
		cin >> t[i][0] >> t[i][1];
		int len1 = t[i][0].length();
		int len2 = t[i][1].length();
		hat[i][0].resize(len1 + 2);
		hat[i][1].resize(len2 + 2);
		hat[i][0][0] = s[i][0][0];
		for(int j = 0; j < len1; j++){
			k = k * base + t[i][0][j];
			hat[i][0][j] = k;
		}
		k = 0;
		for(int j = 0; j < len2; j++){
			k = k * base + t[i][1][j];
			hat[i][1][j] = k;
		}
	}
}

int main(){
	freopen("replace1.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	p[0] = 1;
//	cout << ('b' * base + 'c') << " " << ('d' * base + 'e') << "\n";
	for(int i = 1; i < N - 2; i++){
		p[i] = p[i - 1] * base;
//		cout << p[i] << " ";
	}
	input();
	solvebl();
//	if(q == 1){
//		
//	}
	return 0;
}
