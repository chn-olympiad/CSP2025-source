#include <bits/stdc++.h>
using namespace std;

int n, t, hd;
long long ans=0;
vector <int> a;

int tr(int s, int num, int da, int fr, int en) {
	s+=a[fr];
	num++;
	for (int i=fr+1; i<en; i++) {
		hd+=tr(s, num, da, i, en);
	}
	if (s>da && num>1) {
		return 1;
	}
	return 0;
}

int main() {
	
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	for (int i=a.size()-1; i>=2; i--) {
		for (int j=0; j<i; j++) {
			hd=0;
			tr(0, 0, a[i], j, i);
			ans += hd;
		}
	}
	ans /= 998, 244, 353;
	cout << ans;
	
	return 0;
} 
