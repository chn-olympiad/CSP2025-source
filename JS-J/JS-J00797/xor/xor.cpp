#include<bits/stdc++.h>
#define ll long long
const int N = 5e5 + 10;
using namespace std;

int n, k;
int a[N], sum[N];
map <int, vector <int> > m;
map <int, int> id;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ a[i];
	//for(int i = 0; i <= n; i++) cout << sum[i] << ' ';
	//cout << endl;	

	int r = 0, ans = 0;
	m[0].push_back(0);

	for(int i = 1; i <= n; i++) {
		int dk = sum[i] ^ k;
		//cout << " D" << i << ' ' << dk << endl; 
		if(m[dk].size() > id[dk]) {
			ans++;
			//cout << m[dk][id[dk]] + 1 << ' ' << i << endl;
			for(int j = r; j < i; j++) {
				id[sum[j]]++;
			}
			r = i;
		}
		m[sum[i]].push_back(i);	
	}

	cout << ans;

	return 0;
}
