#include<bits/stdc++.h>
using namespace std;

const int Max = 2e5 + 7;
string a[Max];
string b[Max]; // a -> b 
int n, q, px, py;
string s1, s2;
set<int> d1, d2;
long long ans = 0;

int diff(string a, string b){
	int ans = 0;
	for (int i = 0; i <= a.size(); i++) if (a[i] != b[i]) {
		ans++;
		d1.insert(i);
		if (d1.size() == 1) py = i;
	}
	return ans;
} 

int diff2(string a, string b){
//	cout << "diff2 start --------------\n";
//	cout << "a is " << a << "b is " << b << "\n";
	int ans = 0;
	for (int i = 0; i <= a.size(); i++) if (a[i] != b[i]) {
//		cout << "a[i], b[i] = " << a[i]<< " " << b[i] << "\n";
		ans++;
		d2.insert(i);
		if (d2.size() == 1) px = i;
	}
//	cout << "diff2 end --------------\n";
	return ans;
} 

bool dodiff(int num){
//	cout << "dodiff\n";
	string ss1, ss2;
	for (auto i : d1){
		ss1 += s1[i];
		ss2 += s2[i];
	}
	return (ss1 == a[num] && ss2 == b[num]);
}

bool dodiffmove(int num, int move){
	for (int i = 0; i <= a[num].size(); i++){
//		cout << "a[num][i], s1[i + move] = " << a[num][i] << " " << s1[i + move] << "\n";
		if (a[num][i] != s1[i + move]) return false;
	}
	return true;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	while (q--){
		d1.clear();ans = 0;
		cin >> s1 >> s2;
		int z = diff(s1, s2);
		int qwe = s1.size();
//		cout << "z is " << z << "\n";
		for (int i = 1; i <= n; i++){
			if (a[i].size() < z || a[i].size() > qwe) continue;
			else if (a[i].size() == z) {
//				cout << "now 22222222 but i = " << i << "\n";
				if (dodiff(i)) ans++;
			}
			else if (diff2(a[i], b[i]) == z){
//				cout << "now 33333333 but i = " << i << "\n";
				int move = py - px;
//				cout << "py = " << py << "\n";
//				cout << "px = " << px << "\n";
//				cout << "move = " << move << "\n";
				if (dodiffmove(i, move)) ans++;
				d2.clear();
			}
			else d2.clear();
		}
//		cout << ans << "\n";
		printf("%lld\n", ans);
	}
}
