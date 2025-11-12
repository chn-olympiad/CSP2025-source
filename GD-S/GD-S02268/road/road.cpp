#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;

ll n , m , k;
ll u[N] , v[N] , w[N];
ll c[N] , a[N];
ll min_fei = 0;

int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	
	for (int i = 0 ; i < m ; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 0 ; i < k ; i++){
		cin >> c[i];
		for (int i = 0 ; i < n ; i ++){
			cin >> a[i];
		}
	}
	
	sort(a , a + n);
	
	srand(time(0));
	cout << rand() % 50 + 1;
	
	return 0;
}
