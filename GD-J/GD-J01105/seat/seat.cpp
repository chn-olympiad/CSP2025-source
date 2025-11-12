#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m,s[105],o;
	cin >> n >> m;
	
	for(int i = 1;i <= n*m;i++) {
		cin >> s[i];
	}
	o = s[1];
	sort(s+1,s+n*m+1,greater<int>());
	
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= n;j++) {
			int idx = (i-1)*m+j;
			if(s[idx] == o) {
				if(i % 2 == 1)
					cout << i << ' ' << j;
				else
					cout << i << ' ' << n-j+1;
			}
		}
	}
	return 0;
}

