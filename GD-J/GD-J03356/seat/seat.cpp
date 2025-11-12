#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, m, s, a, t, h, ans1, ans2;
	vector <int> v;
	cin >> n >> m;
	for (int i=0; i<n*m; i++) {
		cin >> s;
		v.push_back(s);
	}
	s=v[0];
	
	sort(v.begin(), v.end());
	
	a=1;
	int i=v.size()-1;
	while(v[i]!=s) {
		a++;
		i--;
	}
	
	t=a/(2*n);
	h=a%(2*n);
	if (h>n) {
		ans1=2*t+2;
		ans2=2*n-h+1;
	}
	else {
		ans1=2*t+1;
		ans2=h;
	}
	
	cout << ans1 << " " << ans2;
	
	
	return 0;
} 
