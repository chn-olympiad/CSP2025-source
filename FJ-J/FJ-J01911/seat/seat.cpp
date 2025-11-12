#include <bits/stdc++.h>
using namespace std;
int s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cnt = 0;
	for(int i = 1;i <= n * m;i++){
		cin >> s[i];
		if(s[i] >= s[1]) cnt++;
	}
	int l = cnt / n + (cnt % n != 0);
	if(l % 2 == 1) cout << l << " " << cnt % n + n * (cnt % n == 0) << endl;
	else cout << l << " " << n - (cnt % n) - n * (cnt % n == 0) + 1 << endl;
	return 0;
}

