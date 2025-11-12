#include<bits/stdc++.h>
using namespace std;
int n,m,x,a,t,c,r; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> a;
	for (int i = 1;i < n * m;i++){
		cin >> t;
		if (t > a) x++;
	}
	c = x / n + 1;
	cout << c << " ";
	if (c % 2) cout << x % n + 1;
	else cout << n - x % n;
	return 0;
} 
