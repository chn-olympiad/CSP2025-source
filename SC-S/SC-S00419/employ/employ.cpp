#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 500;
int n, m, ans,  c[N];
string s;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	do{
		int f = 1;
		for(int i = 1; i <= n; i++){
			if(s[i] == '0') sum[i] = sum[i - 1] + 1;
			else sum[i] = sum[i - 1];
			if(sum[i] > c[i]) f = 0;
		}
		if(f = 1) ans ++;
	}while(next_permutation());
	return 0;
}