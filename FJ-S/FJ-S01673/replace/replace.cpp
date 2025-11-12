#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
const unsigned long long h = 2347;
int n, q, L[200001], M[200001], R[200001];
unsigned long long Left[200001], Mid1[200001], Mid2[200001], Right[200001], hash1[5000001], hash2[5000001], tmp[5000001];
void init(){
	tmp[0] = 1;
	for (int i = 1; i <= 5e6; i++){
		tmp[i] = tmp[i - 1] * h;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	FILE("replace")
	init();
	string s, t;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s >> t;
		if (s == t){
			continue;
		}
		int l = s.size();
		s = " " + s;
		t = " " + t;
		for (int j = 1; j <= l; j++){
			if (s[j] != t[j]){
				L[i] = j - 1;
				break;
			}
		}
		for (int j = l; j >= 1; j--){
			if (s[j] != t[j]){
				R[i] = l - j;
				break;
			}
		}
		M[i] = l - L[i] - R[i];
		for (int j = 1; j <= L[i]; j++){
			Left[i] = Left[i] * h + s[j];
		}
		for (int j = L[i] + 1; j <= l - R[i]; j++){
			Mid1[i] = Mid1[i] * h + s[j];
		}
		for (int j = L[i] + 1; j <= l - R[i]; j++){
			Mid2[i] = Mid2[i] * h + t[j];
		}
		for (int j = l - R[i] + 1; j <= l; j++){
			Right[i] = Right[i] * h + s[j];
		}
	}
	while (q--){
		cin >> s >> t;
		if (s.size() != t.size()){
			cout << "0\n";
			continue;
		}
		int m = s.size(), l, r, res = 0;
		s = " " + s;
		t = " " + t;
		for (int i = 1; i <= m; i++){
			if (s[i] != t[i]){
				l = i - 1;
				break;
			}
		}
		for (int i = m; i >= 1; i--){
			if (s[i] != t[i]){
				r = m - i;
				break;
			}
		}
		for (int i = 1; i <= m; i++){
			hash1[i] = hash1[i - 1] * h + s[i];
		}
		for (int i = 1; i <= m; i++){
			hash2[i] = hash2[i - 1] * h + t[i];
		}
		for (int i = 1; i <= n; i++){
			if (m - l - r != M[i]){
				continue;
			}
			if (hash1[m - r] - hash1[l] * tmp[m - l - r] != Mid1[i]){
				continue;
			}
			if (hash2[m - r] - hash2[l] * tmp[m - l - r] != Mid2[i]){
				continue;
			}
			if (l < L[i] || r < R[i]){
				continue;
			}
			if (hash1[l] - hash1[l - L[i]] * tmp[L[i]] != Left[i]){
				continue;
			}
			if (hash1[m - r + R[i]] - hash1[m - r] * tmp[R[i]] != Right[i]){
				continue;
			}
			res++;
		}
		cout << res << "\n";
	}
	return 0;
}

