#include <iostream>
#include <bits/stl_algo.h>
#include <string>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	{
		ios::sync_with_stdio();
		string a, b;
		cin>>a;
		int i;
		int n = a.length();
		for (i = 0; i < n; i++) {
			if (a[i] >= '0' && a[i] <= '9')b += a[i];

		}

		//cerr << b << endl;

		int m = b.length();
		char max;
		int maxp;
		string c;
		;

		for (int j = 1; j <= m; j++) {
			for (i = 0; i < m; i++) {
				
				max = b[0];
				if (i!=maxp) {
					if (b[i] > max) {
						max = b[i];
						maxp = i;
						b[i] = 0;
					}
				}
				//cerr << maxp << endl;
		if (b[i + 1] > b[i]) swap(b[i], b[i + 1]);
		}
		
		}
		cout << b << endl;




	}
	return 0;
}