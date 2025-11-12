#include <bits/stdc++.h>
using namespace std;

namespace solve{
	void main(){
		int n, m;
		cin >> n >> m;
		vector<int> a(n*m, 0);
		for (int i=0;i<n*m;i++) cin >> a[i];
		int a0 = a[0];
//		cout<<a0<<"\n";
//		sort(a.begin(), a.end(), [](const int& m, const int& n){
//			return m > n;
//		});
		sort(a.begin(), a.end());
		int ind = lower_bound(a.begin(), a.end(), a0)-a.begin();
		ind = n*m-ind -1;
//		cout<<ind<<"\n";
		int c = ind / n +1, r = ind % n +1;
		if (c%2 == 0) r = n+1-r;
		cout << c << " " << r;
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve::main();
	return 0;
}
