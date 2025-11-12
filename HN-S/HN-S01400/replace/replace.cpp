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
const ull base = 2;
string s[N][2], t[N][2];
int n, q;
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
				if(t[i][0].substr(j, slen) == s[k][0] && t[i][1].substr(j, slen) == s[k][1]){
					ans++;
				}
//				cout << getHash(hat[i][0], j, j + slen - 1) << " " << getHash(has[k][0], 0, s[k][0].length() - 1) << "\n";
//				cout << getHash(hat[i][1], j, j + slen - 1) << " " << getHash(has[k][1], 0, s[k][1].length() - 1) << "\n";
//				if(getHash(hat[i][0], j, j + slen - 1) == getHash(has[k][0], 0, s[k][0].length() - 1)&& 
//				     getHash(hat[i][1], j, j + slen - 1) == getHash(has[k][1], 0, s[k][1].length() - 1)){
//					ans++;
//				}
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
	}
	for(int i = 1; i <= q; i++){
		cin >> t[i][0] >> t[i][1];
	}
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	ull x = 1;
//	p[0] = 1;
////	cout << ('b' * base + 'c') << " " << ('d' * base + 'e') << "\n";
//	for(int i = 1; i < 22; i++){
//		p[i] = p[i - 1] * base;
////		cout << p[i] << " ";
//	}
	input();
	solvebl();
//	if(q == 1){
//		
//	}
	return 0;
}
