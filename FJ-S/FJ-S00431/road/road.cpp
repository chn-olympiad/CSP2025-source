#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, ans;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> m;
	while(n--){
		cin >> m >> m >> m;
		ans+=m;
	}
	cout << m << '\n';
	return 0;
}
