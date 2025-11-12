#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, m, a, b, s;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ){
		for (int j = 1; j <= m; j ++ ){
			cin >> b;
			if (i == 1 && j == 1){
				a = b;
			}
			s += (b >= a);
		}
	}
	
	cout << s / n + 1 - (s % n == 0) << " ";
	if ((s / n + 1 - (s % n == 0)) % 2 == 1){
		cout << s - (s / n - (s % n == 0)) * n;
	}
	else{
		cout << n - (s - (s / n - (s % n == 0)) * n) + 1;
	}
	
	return 0;
}