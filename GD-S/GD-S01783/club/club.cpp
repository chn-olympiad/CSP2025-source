#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N][3], s[3], sum, b[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Cases;
	cin >> Cases;
	while(Cases--){
		cin >> n;
		s[0] = s[1] = s[2] = sum = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int t = max(a[i][0], max(a[i][1], a[i][2])), p;
			for(p = 0; p < 2; p++)
				if(a[i][p] == t)
					break;
			s[p]++, sum += t;
		}
		int t = -1;
		for(int i = 0; i < 3; i++)
			if(s[i] > n / 2)
				t = i;
		if(t == -1){
			cout << sum << "\n";
			continue;
		}
		sum = 0;
		for(int i = 1; i <= n; i++){
			b[i] = 0;
			for(int j = 0; j < 3; j++)
				if(j != t)
					b[i] = max(b[i], a[i][j]);
			b[i] = a[i][t] - b[i], sum += a[i][t];
		}
		sort(b + 1, b + n + 1);
		for(int i = 1; i <= n / 2; i++)
			sum -= b[i];
		cout << sum << "\n"; 
	}
}
