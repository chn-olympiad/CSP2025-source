#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[500005], p, s;
map<long long, long long> k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		b[i] = b[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i++){
		k[b[i - 1]] = 1;
		if(a[i] == m){
			p = i;
			s++;
		}
		if(k[b[i] ^ m] != 0 && m != 0){
			if(k[b[i] ^ m] > p){
				p = i;
				s++;
				k[b[i] ^ m] = 0;
			}
		}
	}
	cout << s;
	return 0;
}
