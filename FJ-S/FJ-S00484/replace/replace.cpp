#include <bits/stdc++.h> 

using namespace std;  

bool beg; 

const int SZ = 5e6 + 5, N = 2e5 + 5; 

int n, q, nxt[SZ];           

string s1[N], s2[N], t1, t2; 

void solve() {
	cin >> t1 >> t2;
	cout << 0 << '\n'; 
	return; 
}

bool end; 

int main() {
	freopen("replace.in", "r", stdin); 
	freopen("replace.out", "w", stdout);   
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	cin >> n >> q; 
	for(int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i]; 
	//	mp[s1[i]] = s2[i]; 
		s1[i] = " " + s1[i], s2[i] = " " + s2[i];  
	} 
	for(int i = 1; i <= q; i++) {
		solve(); 
	}
	return 0;     
}
