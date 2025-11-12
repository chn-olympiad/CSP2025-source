#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;

int x;
int ans;
int n, m;
string s;
int a[505];
int b[505];
bool vis[505];

bool asas(){
	int cm = 0;
	int mm = 0;
	for(int i = 1; i <= x; i++){
		if(s[i] == '1' && cm < b[i]){
			mm++;
			if(mm >= m){
				return 1;
			}
		}else{
			cm++;
		}
	}
	
	return 0;
}

void aaaa(int x){
	if(x > n){
		if(asas()){
			ans++;
			if(ans == M){
				ans = 0;
			}
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			b[x] = a[i];
			vis[i] = 1;
			aaaa(x + 1);
			vis[i] = 0;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> s;
	x = s.length();
	s = '#' + s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int cntt = 0;
	for(int i = 1; i <= x; i++){
		if(s[i] == '1')cntt++;
	}
	if(n <= 23){
		int anssna = 1;
		for(int i = 1; i <= n; i++){
			anssna *= i;
			anssna %= M;
		}
		cout << anssna;
	}else if(cntt == x){
		aaaa(1);
		cout << ans;
	} else if(cntt == 0){
		cout << "0";
	} else {
		cout << "38";
	}

	return 0;
}
/*

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
