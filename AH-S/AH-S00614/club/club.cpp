#include <bits/stdc++.h>
using namespace std; 
const long long MAXN = 1e5 + 5; 
long long t, n, a[MAXN][5]; 
vector <long long> d1, d2, d3; 
int main() {
	ios :: sync_with_stdio(false); 
	cin.tie(nullptr), cout.tie(nullptr); 
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	cin >> t; 
	while (t--) {
		cin >> n; 
		long long ans = 0; 
		memset(a, 0, sizeof(a)); 
		d1.clear(), d2.clear(), d3.clear(); 
		for (long long i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3]; 
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3])
				d1.push_back(i), ans += a[i][1]; 
			else if (a[i][2] > a[i][1] && a[i][2] > a[i][3])
				d2.push_back(i), ans += a[i][2]; 
			else 
				d3.push_back(i), ans += a[i][3]; 
		}
		/*
		cout << "ans: " << ans << endl; 
		cout << "size: " << d1.size() << endl; 
		for (long long i = 0; i < d1.size(); i++)
			cout << d1[i] << " "; 
		cout << endl; 
		cout << "size: " << d2.size() << endl; 
		for (long long i = 0; i < d2.size(); i++)
			cout << d2[i] << " "; 
		cout << endl; 
		cout << "size: " << d3.size() << endl; 
		for (long long i = 0; i < d3.size(); i++)
			cout << d3[i] << " "; 
		cout << endl; 
		*/
		if (d1.size() > n / 2) {
			//cout << 1 << endl; 
			vector <long long> del; 
			del.clear(); 
			for (long long i = 0; i < d1.size(); i++)
				del.push_back(min(a[d1[i]][1] - a[d1[i]][2], a[d1[i]][1] - a[d1[i]][3])); 
			sort(del.begin(), del.end()); 
			for (long long i = 0; i < d1.size() - n / 2; i++)
				ans -= del[i]; 
		} else if (d2.size() > n / 2) {
			//cout << 2 << endl; 
			vector <long long> del; 
			del.clear(); 
			for (long long i = 0; i < d2.size(); i++)
				del.push_back(min(a[d2[i]][2] - a[d2[i]][1], a[d2[i]][2] - a[d2[i]][3])); 
			sort(del.begin(), del.end()); 
			for (long long i = 0; i < d2.size() - n / 2; i++)
				ans -= del[i]; 
		} else if (d3.size() > n / 2){
			//cout << 3 << endl; 
			vector <long long> del; 
			del.clear(); 
			for (long long i = 0; i < d3.size(); i++)
				del.push_back(min(a[d3[i]][3] - a[d3[i]][1], a[d3[i]][3] - a[d3[i]][2])); 
			sort(del.begin(), del.end()); 
			for (long long i = 0; i < d3.size() - n / 2; i++)
				ans -= del[i]; 
		}
		cout << ans << endl; 
	}
	return 0; 
}
